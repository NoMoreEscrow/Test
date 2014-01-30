<#
.SYNOPSIS

    Send signal to Illumio Agents.

.PARAMETER SigNumber

    Signal number.
    1. [EventSyncSvc] Dump Handler Map
    2. [EventSyncSvc] Toggle Debug

.OUTPUTS

    None

.EXAMPLE

    Send-Agent-Signal <EventName>

#>

    [CmdletBinding()]
    Param (
        [Parameter(Mandatory = $False, Position = 0)]
        [ValidateNotNullOrEmpty()]
        [Int]$EventNumber
    )

    switch ($EventNumber)
    {
        1 {$EventName = "Global\EventSyncDumpMap"}
        2 {$EventName = "Global\EventSyncDebug"}
        default {Write-Output "Unknown evnet number " + $EventNumber; exit(0)}
    }

    Write-Output "Open Event: $EventName"

 $MethodDefinition = @'
    [DllImport("kernel32.dll", SetLastError=true)]
    public static extern IntPtr CreateEvent(IntPtr lpEventAttributes, bool bManualReset, bool bInitialState, string lpName);
    
    [DllImport("kernel32.dll", SetLastError=true)]
    public static extern bool CloseHandle(IntPtr hObject);

    [DllImport("kernel32.dll", SetLastError=true)]
    public static extern bool SetEvent(IntPtr hObject);
'@

    $Kernel32 = Add-Type -MemberDefinition $MethodDefinition -Name 'Kernel32' -Namespace 'Win32' -PassThru

    # Perform CreateEvent
    $Handle = $Kernel32::CreateEvent(0, $False, $False, $EventName)
    $LastError = [System.Runtime.InteropServices.Marshal]::GetLastWin32Error()

    Write-Output ("Event = " + $EventName + ", handle = " + $Handle + ", Error = " + $LastError)

    if ($LastError -ne 0) {
        Write-Output ("Send signal to existing Event = " + $EventName)
        $retNo = $Kernel32::SetEvent($Handle)
    }

    $retNo = $Kernel32::CloseHandle($Handle)
 