#
#		Makefile ��chip��¸����rx�ѡ�
#

# 
#  ���åװ�¸���ǥ��쥯�ȥ�̾����� 
# 
ARCHDIR = $(SRCDIR)/arch/$(PRC)_$(TOOL)

#
#  ����ѥ��륪�ץ����
#
INCLUDES := $(INCLUDES) -I$(ARCHDIR)
CDEFS := $(CDEFS)
COPTS := $(COPTS)

#
#  �����ͥ�˴ؤ������
#
KERNEL_DIR := $(KERNEL_DIR) $(ARCHDIR)
KERNEL_ASMOBJS := $(KERNEL_ASMOBJS) prc_test.o start.o
KERNEL_COBJS := $(KERNEL_COBJS) rx610_config.o

#
#  �����ƥॵ���ӥ��˴ؤ������
#
SYSSVC_DIR := $(SYSSVC_DIR)
SYSSVC_COBJS := $(SYSSVC_COBJS)

#
#  �ȥ졼�����˴ؤ�������
#
ifeq ($(ENABLE_TRACE),true)
	COPTS := $(COPTS) -DTOPPERS_ENABLE_TRACE
	KERNEL_DIR := $(KERNEL_DIR) $(SRCDIR)/arch/logtrace
	KERNEL_COBJS := $(KERNEL_COBJS) trace_config.o trace_dump.o
endif

#
#  ��¸�ط������
#
kernel_cfg.timestamp: $(ARCHDIR)/rx610.tf
$(OBJFILE): $(ARCHDIR)/prc_check.tf

# 
#  ���ե��åȥե����������Τ������� 
# 
#OFFSET_TF := $(ARCHDIR)/core_offset.tf
OFFSET_TF = $(TARGETDIR)/target_offset.tf

#
#		Makefile �Υץ��å���¸����RX�ѡ�
#

#
#  �ġ����¸���ǥ��쥯�ȥ�̾����� 
#
TOOLDIR = $(SRCDIR)/arch/$(TOOL)

#
#  ����ѥ��륪�ץ����
#
COPTS := $(COPTS)
INCLUDES := $(INCLUDES) -I$(TOOLDIR)
LDFLAGS := -nostdlib $(LDFLAGS) 
CDEFS := $(CDEFS)
LIBS := $(LIBS)  -lgcc

#
#  �����ͥ�˴ؤ������
#
KERNEL_DIR := $(KERNEL_DIR) $(COREDIR)
KERNEL_ASMOBJS := $(KERNEL_ASMOBJS) prc_support.o
KERNEL_COBJS := $(KERNEL_COBJS) prc_config.o

#
#  ��¸�ط������
#
cfg1_out.c: $(ARCHDIR)/prc_def.csv
kernel_cfg.timestamp: $(ARCHDIR)/prc.tf

#
#  ����ե�����졼���ط����ѿ������
#
CFG_TABS := $(CFG_TABS) --cfg1-def-table $(ARCHDIR)/prc_def.csv  
