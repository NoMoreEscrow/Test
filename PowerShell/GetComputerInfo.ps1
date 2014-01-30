<#
.SYNOPSIS
Shows when last your PC started up.
.DESCRIPTION
This is a WMI wrapper function to get the time that your PC last started up.
.PARAMETER ComputerName
The name of the Computer you want to run the command against.
.EXAMPLE
Get-LastBootTime -ComputerName localhost
.LINK
www.howtogeek.com
#>
#param(
#    [Parameter(Mandatory=$true)][string]$ComputerName
#)

Set-ExecutionPolicy RemoteSigned -Force
#Get-WmiObject -Class Win32_OperatingSystem | Format-List -Property *
Get-WmiObject -Class Win32_NetworkAdapter |
#Where-Object {($_.NetEnabled)} | Select-Object -Property CSName,@{n=”Description”;e={$_.Description}}
#Where-Object {($_.NetEnabled)} | Select-Object | Format-Table
Where-Object {$_.NetEnabled -and $_.PhysicalAdapter-and (!($_.Name -like "*virtual*"))} | Out-File C:\ProgramData\Illumio\etc\networkadapter.txt

#Get-WmiObject -Class Win32_IP4RouteTable | Select-Object @{n=”Description”;e={$_.Description}}
