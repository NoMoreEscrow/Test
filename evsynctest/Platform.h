//
// Copyright 2013 Illumio, Inc. All Rights Reserved.
//
#ifndef __PLATFORM_H__
#define __PLATFORM_H__ 1

using namespace std;

/*******************************************************
 *
 * Platform specific types of definitions.  We use this
 * file to try and generate definitions for Linux and
 * Windows platforms.  This allows us to hopefully make
 * the code common.
 *
 ******************************************************/

#ifdef _WIN32
#include "platform_win32.h"

// We look for this file during our configuration check.  If it exists
// we reset the connection to the evservice.  This file is created when our
// network configuration on the sensor changes.
const string fwConfigFile = "/opt/illumio/etc/firewall/ipt_info.cfg";

// We look for this file during our configuration check.  If it exists
// we start sending KEEPALIVE messages to EventService.  This is to prevent
// our EventSync connection from being timed out by the datacenter.
const string keepAliveFile = "/opt/illumio/etc/.keepalive_flag";

// CONFIGURATION files
const string serverConfFileName = "master_cfg.ini";
const string sidFileName = "agent_id.ini";

#else // !WIN32
#include <errno.h>
#include <pthread.h>
#include <unistd.h>
#include <netdb.h>
#include <dirent.h>
#include <pwd.h>
#include <resolv.h>
#include <sys/prctl.h>
#include <sys/socket.h>
#include <arpa/inet.h>

// We look for this file during our configuration check.  If it exists
// we reset the connection to the evservice.  This file is created when our
// network configuration on the sensor changes.
const string fwConfigFile = "/opt/illumio/etc/firewall/ipt_info.cfg";

// We look for this file during our configuration check.  If it exists
// we start sending KEEPALIVE messages to EventService.  This is to prevent
// our EventSync connection from being timed out by the datacenter.
const string keepAliveFile = "/opt/illumio/etc/.keepalive_flag";

// CONFIGURATION files
const string serverConfFileName = "/opt/illumio/etc/agent_master_config.yml";
const string sidFileName = "/opt/illumio/etc/agent_id.cfg";

const string server_cert_file_path1 = "/etc/ssl/certs/ca-bundle.crt";
const string server_cert_file_path2 = "/etc/ssl/certs/ca-certificates.crt";

#endif // WIN32

#endif
