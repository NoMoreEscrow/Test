#
# Copyright 2013 Illumio, Inc. All Rights Reserved.
#
# EventProcessor Makefile
TOP := $(shell while [ `pwd` != '/' ]; do if [ -d "control" ]; then echo `pwd`; break; fi; cd ..; done)

COMP_NAME := $(shell basename `pwd`)
BUILD_ROOT := $(TOP)/build_root
RPM_ROOT := $(TOP)/rpm_root
DBG_ROOT := $(TOP)/debug_root
RPM_OUT_DIR := $(TOP)/rpms
DEB_OUT_DIR := $(TOP)/debs

OS_RELEASE := $(firstword $(shell cat /etc/issue))
OS_VERSION := unknown

ifeq ($(OS_RELEASE),Red)
OS_VERSION := $(shell cat /etc/issue | grep release | awk '{print $7}')
endif

ifeq ($(OS_RELEASE),CentOS)
OS_VERSION := $(word 3, $(shell cat /etc/issue))
endif

ifeq ($(OS_VERSION),5.9)
OS_RELEASE := RHEL59
endif

COMP_OBJ_DIR := $(BUILD_ROOT)/$(OS_RELEASE)/$(COMP_NAME)

# Part of control RPM
RPM_COMP_NAME := control
COMP_RPM_ROOT := $(RPM_ROOT)/$(OS_RELEASE)/$(RPM_COMP_NAME)
COMP_RPM_DIR := $(COMP_RPM_ROOT)/opt/illumio

CC=g++

CFLAGS=-O2 -Wall -g -D_REENTRANT -pthread
IFLAGS=-I.
LDFLAGS=-lpthread

EXE=EventSyncTest

SOURCES=main.cpp EventSocket.cpp LogMessage.cpp
OBJECTS=$(SOURCES:.cpp=.o)

TARGET_OBJ_FILES := $(addprefix $(COMP_OBJ_DIR)/, $(EXE)) 
TARGET_OBJ_FILES += $(addprefix $(COMP_OBJ_DIR)/, $(BIN_DATA)) 

TARGET_RPM_FILES := $(addprefix $(EXE_DST)/, $(EXE))

TARGET_DBG_FILES := $(addprefix $(COMP_DBG_DIR)/, $(EXE).dbg)

.cpp.o:
	$(CC) -c $(CFLAGS) $(IFLAGS) $< -o $@

$(COMP_OBJ_DIR)/%: %
	install -D $< $@

$(COMP_DBG_DIR)/%: %
	install -D $< $@

$(COMP_OBJ_DIR)/%: datafiles/%
	install -D $< $@

$(COMP_OBJ_DIR)/%: datafiles/%.$(OS_RELEASE)
	install -D $< $@

$(EXE_DST)/%: $(COMP_OBJ_DIR)/%
	install -D $< $@

$(BIN_DATA_DST)/%: $(COMP_OBJ_DIR)/%
	install -D $< $@

$(ETC_DATA_DST)/%: $(COMP_OBJ_DIR)/%
	install -D $< $@

$(EXE): $(OBJECTS)
	$(CC) $(CFLAGS) $(IFLAGS) -o $(EXE) $(OBJECTS) $(LDFLAGS)

all: compile

compile: $(OBJECTS)

link: $(EXE)

install:
	@echo "Nothing to do"

rpm:
	@echo "Nothing to do"

deb:
	@echo "Nothing to do"

clean:
	-rm -f *.o
	-rm -f EventSyncTest
	-rm -f $(TARGET_RPM_FILES)
	-rm -fr $(COMP_OBJ_DIR)
	-rm -fr $(COMP_DBG_DIR)/$(EXE).dbg

clobber: clean

debug:
	@echo "TARGET_RPM_FILES: $(TARGET_RPM_FILES)"
	@echo "TARGET_OBJ_FILES: $(TARGET_OBJ_FILES)"
