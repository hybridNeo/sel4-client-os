#
# @author - Rahul Mahadev
#
# This software may be distributed and modified according to the terms of
# the BSD 2-Clause license. Note that NO WARRANTY is provided.
# See "LICENSE_BSD2.txt" for details.
#
#
#

apps-$(CONFIG_APP_CLIENT_OS) += client-os


client-os-y = common libsel4 libmuslc \
            libsel4muslcsys \
            libsel4simple libsel4vka libsel4allocman libsel4vspace \
	    libsel4platsupport \
            libsel4utils \
            libcpio libelf \
            libutils

ifdef CONFIG_KERNEL_STABLE
client-os-$(CONFIG_LIB_SEL4_SIMPLE_STABLE) += libsel4simple-stable
else
client-os-$(CONFIG_LIB_SEL4_SIMPLE_DEFAULT) += libsel4simple-default
endif


components-$(CONFIG_APP_CLIENT_OS) += client-os
client-os: common libsel4 libmuslc libsel4muslcsys libutils
client-os-components-y += client-app
client-os-components = $(addprefix $(STAGE_BASE)/bin/, $(client-os-components-y))

client-os: export COMPONENTS=${client-os-components}
client-os: ${client-os-components-y} kernel_elf $(client-os-y)

