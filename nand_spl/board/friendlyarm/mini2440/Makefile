#
# (C) Copyright 2007
# Stefan Roese, DENX Software Engineering, sr@denx.de.
#
# Copyright 2009-2011 Freescale Semiconductor, Inc.
#
# SPDX-License-Identifier:	GPL-2.0+
#
include $(srctree)/nand_spl/board/$(BOARDDIR)/config.mk

CONFIG_NAND_SPL	= y
CONFIG_S3C2410_NAND_HWECC = y

nandobj	:= $(objtree)/nand_spl/

LDSCRIPT= $(srctree)/nand_spl/board/$(BOARDDIR)/u-boot.lds
LDFLAGS := -T $(nandobj)u-boot.lds -Ttext 0 $(LDFLAGS) \
	   $(LDFLAGS_FINAL)
asflags-y += -DCONFIG_NAND_SPL -DCONFIG_S3C2410_NAND_HWECC
ccflags-y += -DCONFIG_NAND_SPL -DCONFIG_S3C2410_NAND_HWECC

COBJS-$(CONFIG_NAND_SPL) += nand_boot.o nand_ecc.o s3c2410_nand.o nand_spl.o

SOBJS	= start.o crt0.o lowlevel_init.o 
COBJS	:= $(sort $(COBJS-y))

SRCS	:= $(addprefix $(obj)/,$(SOBJS:.o=.S) $(COBJS:.o=.c))
OBJS	:= $(addprefix $(obj)/,$(SOBJS) $(COBJS))
__OBJS	:= $(SOBJS) $(COBJS)
LNDIR	:= $(nandobj)board/$(BOARDDIR)

targets += $(__OBJS)

all: $(nandobj)u-boot-spl $(nandobj)u-boot-spl.bin $(nandobj)u-boot-spl-16k.bin

$(nandobj)u-boot-spl-16k.bin: $(nandobj)u-boot-spl
	$(OBJCOPY) $(OBJCOPYFLAGS) --pad-to=$(PAD_TO) -O binary $< $@

$(nandobj)u-boot-spl.bin:	$(nandobj)u-boot-spl
	$(OBJCOPY) $(OBJCOPYFLAGS) -O binary $< $@

$(nandobj)u-boot-spl:	$(OBJS) $(nandobj)u-boot.lds
	cd $(LNDIR) && $(LD) $(LDFLAGS) $(__OBJS)  \
		-Map $(nandobj)u-boot-spl.map -o $@

$(nandobj)u-boot.lds: $(LDSCRIPT)
	$(CPP) $(cpp_flags) $(LDPPFLAGS) \
		-ansi -D__ASSEMBLY__ -P - <$< >$@

# create symbolic links for common files

# from cpu directory
$(obj)/start.S:
	@rm -f $@
	@ln -s $(srctree)/arch/arm/cpu/arm920t/start.S $@

$(obj)/crt0.S:
	@rm -f $@
	@ln -s $(srctree)/arch/arm/lib/crt0.S $@


# from nand_spl directory
$(obj)/nand_boot.c:
	@rm -f $@
	@ln -s $(srctree)/nand_spl/nand_boot.c $@


# from drivers/mtd/nand directory
$(obj)/nand_ecc.c:
	@rm -f $@
	@ln -s $(srctree)/drivers/mtd/nand/nand_ecc.c $@


$(obj)/s3c2410_nand.c:
	@rm -f $@
	@ln -s $(srctree)/drivers/mtd/nand/s3c2410_nand.c $@
$(obj)/nand_spl.c:
	@rm -f $@
	@ln -s $(srctree)/board/friendlyarm/mini2440/nand_spl.c $@
$(obj)/lowlevel_init.S:
	@rm -f $@
	@ln -s $(srctree)/board/friendlyarm/mini2440/lowlevel_init.S $@
#########################################################################
