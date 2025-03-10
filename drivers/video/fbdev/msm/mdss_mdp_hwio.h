/* SPDX-License-Identifier: GPL-2.0-only */
/* Copyright (c) 2012-2018, 2020, The Linux Foundation. All rights reserved.
 * Copyright (c) 2024 Qualcomm Innovation Center, Inc. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#ifndef MDSS_MDP_HWIO_H
#define MDSS_MDP_HWIO_H

#include <linux/bitops.h>

/*
 * struct mdss_mdp_hwio_cfg - used to define a register bitfield
 * @start: bitfield offset start from lsb
 * @len: number of lsb bits that can be taken from field value
 * @shift: number of lsb bits to truncate from field value
 */
struct mdss_mdp_hwio_cfg {
	u32 start, len, shift;
};

static inline u32 mdss_mdp_hwio_mask(struct mdss_mdp_hwio_cfg *cfg, u32 val)
{
	u32 mask = (1 << cfg->len) - 1;

	return ((val >> cfg->shift) & mask) << cfg->start;
}

#define IGC_LUT_ENTRIES	256
#define GC_LUT_SEGMENTS	16
#define ENHIST_LUT_ENTRIES 256
#define HIST_V_SIZE	256

/* QSEED3 LUT sizes */
#define DIR_LUT_IDX		1
#define DIR_LUT_COEFFS		200
#define CIR_LUT_IDX		9
#define CIR_LUT_COEFFS		60
#define SEP_LUT_IDX		10
#define SEP_LUT_COEFFS		60


#define MDSS_MDP_FETCH_CONFIG_RESET_VALUE	0x00000087

#define MDSS_REG_HW_VERSION				0x0
#define MDSS_REG_HW_INTR_STATUS				0x10

#define MDSS_INTR_MDP				BIT(0)
#define MDSS_INTR_DSI0				BIT(4)
#define MDSS_INTR_DSI1				BIT(5)
#define MDSS_INTR_HDMI				BIT(8)
#define MDSS_INTR_EDP				BIT(12)

#define MDSS_MDP_REG_HW_VERSION				0x0
#define MDSS_MDP_REG_DISP_INTF_SEL			0x00004
#define MDSS_MDP_REG_INTR2_EN				0x00008
#define MDSS_MDP_REG_INTR2_STATUS			0x0000C
#define MDSS_MDP_REG_INTR2_CLEAR			0x0002C
#define MDSS_MDP_REG_INTR_EN				0x00010
#define MDSS_MDP_REG_INTR_STATUS			0x00014
#define MDSS_MDP_REG_INTR_CLEAR				0x00018
#define MDSS_MDP_REG_HIST_INTR_EN			0x0001C
#define MDSS_MDP_REG_HIST_INTR_STATUS			0x00020
#define MDSS_MDP_REG_HIST_INTR_CLEAR			0x00024
#define MMSS_MDP_MDP_SSPP_SPARE_0			0x00028

#define MMSS_MDP_PANIC_ROBUST_CTRL			0x00178
#define MMSS_MDP_PANIC_LUT0				0x0017C
#define MMSS_MDP_PANIC_LUT1				0x00180
#define MMSS_MDP_ROBUST_LUT				0x00184
#define MMSS_MDP_RT_NRT_VBIF_CLIENT_SEL			0x00190

#define MDSS_MDP_REG_VIDEO_INTF_UNDERFLOW_CTL		0x002E0
#define MDSS_MDP_REG_SPLIT_DISPLAY_EN			0x002F4
#define MDSS_MDP_REG_SPLIT_DISPLAY_UPPER_PIPE_CTRL	0x002F8
#define MDSS_MDP_DANGER_STATUS				0x00360
#define MDSS_MDP_SAFE_STATUS				0x00364
#define MDSS_MDP_REG_SPLIT_DISPLAY_LOWER_PIPE_CTRL	0x003F0
#define MDSS_MDP_REG_DCE_SEL				0x00450

#define MDSS_INTF_DSI	0x1
#define MDSS_INTF_HDMI	0x3
#define MDSS_INTF_LCDC	0x5
#define MDSS_INTF_EDP	0x9

#define MDSS_MDP_INTR_WB_0_DONE				BIT(0)
#define MDSS_MDP_INTR_WB_1_DONE				BIT(1)
#define MDSS_MDP_INTR_WB_2_DONE				BIT(4)
#define MDSS_MDP_INTR_PING_PONG_0_DONE			BIT(8)
#define MDSS_MDP_INTR_PING_PONG_1_DONE			BIT(9)
#define MDSS_MDP_INTR_PING_PONG_2_DONE			BIT(10)
#define MDSS_MDP_INTR_PING_PONG_3_DONE			BIT(11)
#define MDSS_MDP_INTR_PING_PONG_0_RD_PTR		BIT(12)
#define MDSS_MDP_INTR_PING_PONG_1_RD_PTR		BIT(13)
#define MDSS_MDP_INTR_PING_PONG_2_RD_PTR		BIT(14)
#define MDSS_MDP_INTR_PING_PONG_3_RD_PTR		BIT(15)
#define MDSS_MDP_INTR_PING_PONG_0_WR_PTR		BIT(16)
#define MDSS_MDP_INTR_PING_PONG_1_WR_PTR		BIT(17)
#define MDSS_MDP_INTR_PING_PONG_2_WR_PTR		BIT(18)
#define MDSS_MDP_INTR_PING_PONG_3_WR_PTR		BIT(19)
#define MDSS_MDP_INTR_PING_PONG_0_AUTOREFRESH_DONE	BIT(20)
#define MDSS_MDP_INTR_PING_PONG_1_AUTOREFRESH_DONE	BIT(21)
#define MDSS_MDP_INTR_PING_PONG_2_AUTOREFRESH_DONE	BIT(22)
#define MDSS_MDP_INTR_PING_PONG_3_AUTOREFRESH_DONE	BIT(23)
#define MDSS_MDP_INTR_INTF_0_UNDERRUN			BIT(24)
#define MDSS_MDP_INTR_INTF_0_VSYNC			BIT(25)
#define MDSS_MDP_INTR_INTF_1_UNDERRUN			BIT(26)
#define MDSS_MDP_INTR_INTF_1_VSYNC			BIT(27)
#define MDSS_MDP_INTR_INTF_2_UNDERRUN			BIT(28)
#define MDSS_MDP_INTR_INTF_2_VSYNC			BIT(29)
#define MDSS_MDP_INTR_INTF_3_UNDERRUN			BIT(30)
#define MDSS_MDP_INTR_INTF_3_VSYNC			BIT(31)

#define MDSS_MDP_INTR2_PING_PONG_2_CWB_OVERFLOW	        BIT(14)
#define MDSS_MDP_INTR2_PING_PONG_3_CWB_OVERFLOW	        BIT(15)

#define MDSS_MDP_HIST_INTR_VIG_0_DONE			BIT(0)
#define MDSS_MDP_HIST_INTR_VIG_0_RESET_DONE		BIT(1)
#define MDSS_MDP_HIST_INTR_VIG_1_DONE			BIT(4)
#define MDSS_MDP_HIST_INTR_VIG_1_RESET_DONE		BIT(5)
#define MDSS_MDP_HIST_INTR_VIG_2_DONE			BIT(8)
#define MDSS_MDP_HIST_INTR_VIG_2_RESET_DONE		BIT(9)
#define MDSS_MDP_HIST_INTR_VIG_3_DONE			BIT(10)
#define MDSS_MDP_HIST_INTR_VIG_3_RESET_DONE		BIT(11)
#define MDSS_MDP_HIST_INTR_DSPP_0_DONE			BIT(12)
#define MDSS_MDP_HIST_INTR_DSPP_0_RESET_DONE		BIT(13)
#define MDSS_MDP_HIST_INTR_DSPP_1_DONE			BIT(16)
#define MDSS_MDP_HIST_INTR_DSPP_1_RESET_DONE		BIT(17)
#define MDSS_MDP_HIST_INTR_DSPP_2_DONE			BIT(20)
#define MDSS_MDP_HIST_INTR_DSPP_2_RESET_DONE		BIT(21)
#define MDSS_MDP_HIST_INTR_DSPP_3_DONE			BIT(22)
#define MDSS_MDP_HIST_INTR_DSPP_3_RESET_DONE		BIT(23)

enum mdss_mdp_intr_type {
	MDSS_MDP_IRQ_TYPE_WB_ROT_COMP,
	MDSS_MDP_IRQ_TYPE_WB_WFD_COMP,
	MDSS_MDP_IRQ_TYPE_PING_PONG_COMP,
	MDSS_MDP_IRQ_TYPE_PING_PONG_RD_PTR,
	MDSS_MDP_IRQ_TYPE_PING_PONG_WR_PTR,
	MDSS_MDP_IRQ_TYPE_PING_PONG_AUTO_REF,
	MDSS_MDP_IRQ_TYPE_INTF_UNDER_RUN,
	MDSS_MDP_IRQ_TYPE_INTF_VSYNC,
	MDSS_MDP_IRQ_TYPE_CWB_OVERFLOW,
};

#define MDSS_MDP_INTF_INTR_PROG_LINE		BIT(8)

enum mdss_mdp_intf_intr_type {
	MDSS_MDP_INTF_IRQ_PROG_LINE = 8,
};

#define MDSS_MDP_REG_IGC_VIG_BASE			0x200
#define MDSS_MDP_REG_IGC_RGB_BASE			0x210
#define MDSS_MDP_REG_IGC_DMA_BASE			0x220
#define MDSS_MDP_REG_IGC_DSPP_BASE			0x300

enum mdss_mdp_ctl_index {
	MDSS_MDP_CTL0,
	MDSS_MDP_CTL1,
	MDSS_MDP_CTL2,
	MDSS_MDP_CTL3,
	MDSS_MDP_CTL4,
	MDSS_MDP_CTL5,
	MDSS_MDP_MAX_CTL
};


#define MDSS_MDP_REG_CTL_LAYER_EXTN_OFFSET		0x40
#define MDSS_MDP_REG_CTL_LAYER_EXTN2_OFFSET		0x70
#define MDSS_MDP_CTL_X_LAYER_5				0x24

/* mixer 5 has different offset than others */
#define MDSS_MDP_REG_CTL_LAYER(lm)	\
	(((lm) == 5) ? MDSS_MDP_CTL_X_LAYER_5 : ((lm) * 0x004))

#define MDSS_MDP_REG_CTL_LAYER_EXTN(lm)	\
	 (MDSS_MDP_REG_CTL_LAYER_EXTN_OFFSET + ((lm) * 0x004))

#define MDSS_MDP_REG_CTL_LAYER_EXTN2(lm)	\
	 (MDSS_MDP_REG_CTL_LAYER_EXTN2_OFFSET + ((lm) * 0x004))

#define MDSS_MDP_REG_CTL_TOP				0x014
#define MDSS_MDP_REG_CTL_FLUSH				0x018
#define MDSS_MDP_REG_CTL_START				0x01C
#define MDSS_MDP_REG_CTL_PACK_3D			0x020
#define MDSS_MDP_REG_CTL_SW_RESET			0x030

#define MDSS_MDP_CTL_OP_VIDEO_MODE		(0 << 17)
#define MDSS_MDP_CTL_OP_CMD_MODE		(1 << 17)

#define MDSS_MDP_CTL_OP_ROT0_MODE		0x1
#define MDSS_MDP_CTL_OP_ROT1_MODE		0x2
#define MDSS_MDP_CTL_OP_WB0_MODE		0x3
#define MDSS_MDP_CTL_OP_WB1_MODE		0x4
#define MDSS_MDP_CTL_OP_WFD_MODE		0x5

#define MDSS_MDP_CTL_OP_PACK_3D_ENABLE		BIT(19)
#define MDSS_MDP_CTL_OP_PACK_3D_FRAME_INT	(0 << 20)
#define MDSS_MDP_CTL_OP_PACK_3D_H_ROW_INT	(1 << 20)
#define MDSS_MDP_CTL_OP_PACK_3D_V_ROW_INT	(2 << 20)
#define MDSS_MDP_CTL_OP_PACK_3D_COL_INT		(3 << 20)

enum mdss_mdp_sspp_index {
	MDSS_MDP_SSPP_VIG0,
	MDSS_MDP_SSPP_VIG1,
	MDSS_MDP_SSPP_VIG2,
	MDSS_MDP_SSPP_RGB0,
	MDSS_MDP_SSPP_RGB1,
	MDSS_MDP_SSPP_RGB2,
	MDSS_MDP_SSPP_DMA0,
	MDSS_MDP_SSPP_DMA1,
	MDSS_MDP_SSPP_VIG3,
	MDSS_MDP_SSPP_RGB3,
	MDSS_MDP_SSPP_CURSOR0,
	MDSS_MDP_SSPP_CURSOR1,
	MDSS_MDP_SSPP_DMA2,
	MDSS_MDP_SSPP_DMA3,
	MDSS_MDP_MAX_SSPP,
};

enum mdss_mdp_sspp_fetch_type {
	MDSS_MDP_PLANE_INTERLEAVED,
	MDSS_MDP_PLANE_PLANAR,
	MDSS_MDP_PLANE_PSEUDO_PLANAR,
};

enum mdss_mdp_sspp_chroma_samp_type {
	MDSS_MDP_CHROMA_RGB,
	MDSS_MDP_CHROMA_H2V1,
	MDSS_MDP_CHROMA_H1V2,
	MDSS_MDP_CHROMA_420
};

#define MDSS_MDP_REG_SSPP_SRC_SIZE			0x000
#define MDSS_MDP_REG_SSPP_SRC_IMG_SIZE			0x004
#define MDSS_MDP_REG_SSPP_SRC_XY			0x008
#define MDSS_MDP_REG_SSPP_OUT_SIZE			0x00C
#define MDSS_MDP_REG_SSPP_OUT_XY			0x010
#define MDSS_MDP_REG_SSPP_SRC0_ADDR			0x014
#define MDSS_MDP_REG_SSPP_SRC1_ADDR			0x018
#define MDSS_MDP_REG_SSPP_SRC2_ADDR			0x01C
#define MDSS_MDP_REG_SSPP_SRC3_ADDR			0x020
#define MDSS_MDP_REG_SSPP_SRC_YSTRIDE0			0x024
#define MDSS_MDP_REG_SSPP_SRC_YSTRIDE1			0x028
#define MDSS_MDP_REG_SSPP_STILE_FRAME_SIZE		0x02C
#define MDSS_MDP_REG_SSPP_SRC_FORMAT			0x030
#define MDSS_MDP_REG_SSPP_SRC_UNPACK_PATTERN		0x034
#define MDSS_MDP_REG_SSPP_SRC_OP_MODE			0x038
#define MDSS_MDP_REG_SSPP_SRC_CONSTANT_COLOR		0x03C
#define MDSS_MDP_REG_SSPP_REQPRIO_FIFO_WM_0		0x050
#define MDSS_MDP_REG_SSPP_REQPRIO_FIFO_WM_1		0x054
#define MDSS_MDP_REG_SSPP_REQPRIO_FIFO_WM_2		0x058
#define MDSS_MDP_REG_SSPP_DANGER_LUT			0x060
#define MDSS_MDP_REG_SSPP_SAFE_LUT			0x064
#define MDSS_MDP_REG_SSPP_CREQ_LUT			0x068
#define MDSS_MDP_REG_SSPP_QOS_CTRL			0x06C
#define MDSS_MDP_REG_SSPP_CDP_CTRL			0x134
#define MDSS_MDP_REG_SSPP_UBWC_ERROR_STATUS		0x138
#define MDSS_MDP_REG_SSPP_TRAFFIC_SHAPER		0x130
#define MDSS_MDP_REG_SSPP_TRAFFIC_SHAPER_PREFILL	0x150
#define MDSS_MDP_REG_SSPP_TRAFFIC_SHAPER_REC1_PREFILL	0x154

#define MDSS_MDP_REG_SSPP_MULTI_REC_OP_MODE		0x170
#define MDSS_MDP_REG_SSPP_OUT_SIZE_REC1			0x160
#define MDSS_MDP_REG_SSPP_OUT_XY_REC1			0x164
#define MDSS_MDP_REG_SSPP_SRC_XY_REC1			0x168
#define MDSS_MDP_REG_SSPP_SRC_SIZE_REC1			0x16C
#define MDSS_MDP_REG_SSPP_SRC_FORMAT_REC1		0x174
#define MDSS_MDP_REG_SSPP_SRC_UNPACK_PATTERN_REC1	0x178
#define MDSS_MDP_REG_SSPP_SRC_OP_MODE_REC1		0x17C
#define MDSS_MDP_REG_SSPP_SRC_CONSTANT_COLOR_REC1	0x180

#define MDSS_MDP_OP_DEINTERLACE			BIT(22)
#define MDSS_MDP_OP_DEINTERLACE_ODD		BIT(23)
#define MDSS_MDP_OP_IGC_ROM_1			BIT(18)
#define MDSS_MDP_OP_IGC_ROM_0			BIT(17)
#define MDSS_MDP_OP_IGC_EN			BIT(16)
#define MDSS_MDP_OP_FLIP_UD			BIT(14)
#define MDSS_MDP_OP_FLIP_LR			BIT(13)
#define MDSS_MDP_OP_BWC_EN			BIT(0)
#define MDSS_MDP_OP_BWC_LOSSLESS		(0 << 1)
#define MDSS_MDP_OP_BWC_Q_HIGH			(1 << 1)
#define MDSS_MDP_OP_BWC_Q_MED			(2 << 1)

#define MDSS_MDP_REG_SSPP_SRC_CONSTANT_COLOR		0x03C
#define MDSS_MDP_REG_SSPP_FETCH_CONFIG			0x048
#define MDSS_MDP_REG_SSPP_VC1_RANGE			0x04C
#define MDSS_MDP_REG_SSPP_SRC_ADDR_SW_STATUS		0x070

#define MDSS_MDP_REG_SSPP_CURRENT_SRC0_ADDR		0x0A4
#define MDSS_MDP_REG_SSPP_CURRENT_SRC1_ADDR		0x0A8
#define MDSS_MDP_REG_SSPP_CURRENT_SRC2_ADDR		0x0AC
#define MDSS_MDP_REG_SSPP_CURRENT_SRC3_ADDR		0x0B0
#define MDSS_MDP_REG_SSPP_DECIMATION_CONFIG		0x0B4
#define MDSS_MDP_REG_SSPP_SW_PIX_EXT_C0_LR		0x100
#define MDSS_MDP_REG_SSPP_SW_PIX_EXT_C0_TB		0x104
#define MDSS_MDP_REG_SSPP_SW_PIX_EXT_C0_REQ_PIXELS	0x108

#define MDSS_MDP_REG_VIG_OP_MODE			0x200
#define MDSS_MDP_REG_VIG_QSEED2_CONFIG			0x204
#define MDSS_MDP_REG_VIG_QSEED2_C03_PHASESTEPX		0x210
#define MDSS_MDP_REG_VIG_QSEED2_C03_PHASESTEPY		0x214
#define MDSS_MDP_REG_VIG_QSEED2_C12_PHASESTEPX		0x218
#define MDSS_MDP_REG_VIG_QSEED2_C12_PHASESTEPY		0x21C
#define MDSS_MDP_REG_VIG_QSEED2_C03_INIT_PHASEX		0x220
#define MDSS_MDP_REG_VIG_QSEED2_C03_INIT_PHASEY		0x224
#define MDSS_MDP_REG_VIG_QSEED2_C12_INIT_PHASEX		0x228
#define MDSS_MDP_REG_VIG_QSEED2_C12_INIT_PHASEY		0x22C
#define MDSS_MDP_REG_VIG_QSEED2_SHARP			0x230
#define MDSS_MDP_REG_VIG_MEM_COL_BASE			0x288
#define MDSS_MDP_REG_VIG_PA_BASE			0x310

/* QSEED3 registers shared by VIG and Destination Scaler */
#define MDSS_MDP_REG_SCALER_HW_VERSION			0x00
#define MDSS_MDP_REG_SCALER_OP_MODE			0x04
#define MDSS_MDP_REG_SCALER_RGB2Y_COEFF			0x08
#define MDSS_MDP_REG_SCALER_PHASE_INIT			0x0C
#define MDSS_MDP_REG_SCALER_PHASE_STEP_Y_H		0x10
#define MDSS_MDP_REG_SCALER_PHASE_STEP_Y_V		0x14
#define MDSS_MDP_REG_SCALER_PHASE_STEP_UV_H		0x18
#define MDSS_MDP_REG_SCALER_PHASE_STEP_UV_V		0x1C
#define MDSS_MDP_REG_SCALER_PRELOAD			0x20
#define MDSS_MDP_REG_SCALER_DE_SHARPEN			0x24
#define MDSS_MDP_REG_SCALER_DE_SHARPEN_CTL		0x28
#define MDSS_MDP_REG_SCALER_DE_SHAPE_CTL		0x2C
#define MDSS_MDP_REG_SCALER_DE_THRESHOLD		0x30
#define MDSS_MDP_REG_SCALER_DE_ADJUST_DATA_0		0x34
#define MDSS_MDP_REG_SCALER_DE_ADJUST_DATA_1		0x38
#define MDSS_MDP_REG_SCALER_DE_ADJUST_DATA_2		0x3C
#define MDSS_MDP_REG_SCALER_SRC_SIZE_Y_RGB_A		0x40
#define MDSS_MDP_REG_SCALER_SRC_SIZE_UV			0x44
#define MDSS_MDP_REG_SCALER_DST_SIZE			0x48
#define MDSS_MDP_REG_SCALER_COEF_LUT_CTRL		0x4C
#define MDSS_MDP_REG_SCALER_BUFFER_CTRL			0x50
#define MDSS_MDP_REG_SCALER_CLK_CTRL0			0x54
#define MDSS_MDP_REG_SCALER_CLK_CTRL1			0x58
#define MDSS_MDP_REG_SCALER_CLK_STATUS			0x5C
#define MDSS_MDP_REG_SCALER_MISR_CTRL			0x70
#define MDSS_MDP_REG_SCALER_MISR_SIGNATURE_0		0x74
#define MDSS_MDP_REG_SCALER_MISR_SIGNATURE_1		0x78

/* Destination scaler TOP registers */
#define MDSS_MDP_REG_DEST_SCALER_OP_MODE		0x00
#define MDSS_MDP_REG_DEST_SCALER_HW_VERSION		0x10

#define SCALER_EN			BIT(0)
#define SCALER_DIR_EN			BIT(4)
#define SCALER_DE_EN			BIT(8)
#define SCALER_ALPHA_EN			BIT(10)
#define SCALER_COLOR_SPACE		12
#define SCALER_BIT_WIDTH		14
#define Y_FILTER_CFG			16
#define UV_FILTER_CFG			24
#define ALPHA_FILTER_CFG		30
#define SCALER_BLEND_CFG		31

#define PHASE_BITS			0x3F
#define PHASE_STEP_BITS			0xFFFFFF
#define PRELOAD_BITS			0x7F

#define Y_PHASE_INIT_H			0
#define Y_PHASE_INIT_V			8
#define UV_PHASE_INIT_H			16
#define UV_PHASE_INIT_V			24
#define Y_PRELOAD_H			0
#define Y_PRELOAD_V			8
#define UV_PRELOAD_H			16
#define UV_PRELOAD_V			24
/* supported filters */
#define EDGE_DIRECTED_2D		0x0
#define CIRCULAR_2D			0x1
#define SEPERABLE_1D			0x2
#define BILINEAR			0x3
#define ALPHA_DROP_REPEAT		0x0
#define ALPHA_BILINEAR			0x1


/* in mpq product */
#define MDSS_MDP_REG_VIG_FLUSH_SEL			0x204

#define MDSS_MDP_VIG_OP_PA_SAT_ZERO_EXP_EN		BIT(2)
#define MDSS_MDP_VIG_OP_PA_MEM_PROTECT_EN		BIT(3)
#define MDSS_MDP_VIG_OP_PA_EN				BIT(4)
#define MDSS_MDP_VIG_OP_PA_MEM_COL_SKIN_MASK		BIT(5)
#define MDSS_MDP_VIG_OP_PA_MEM_COL_FOL_MASK		BIT(6)
#define MDSS_MDP_VIG_OP_PA_MEM_COL_SKY_MASK		BIT(7)
#define MDSS_MDP_VIG_OP_HIST_LUTV_EN			BIT(10)
#define MDSS_MDP_VIG_OP_PA_HUE_MASK			BIT(25)
#define MDSS_MDP_VIG_OP_PA_SAT_MASK			BIT(26)
#define MDSS_MDP_VIG_OP_PA_VAL_MASK			BIT(27)
#define MDSS_MDP_VIG_OP_PA_CONT_MASK			BIT(28)

#define MDSS_MDP_REG_SCALE_CONFIG			0x204
#define MDSS_MDP_REG_SCALE_PHASE_STEP_X			0x210
#define MDSS_MDP_REG_SCALE_PHASE_STEP_Y			0x214
#define MDSS_MDP_REG_SCALE_INIT_PHASE_X			0x220
#define MDSS_MDP_REG_SCALE_INIT_PHASE_Y			0x224

#define MDSS_MDP_REG_VIG_CSC_1_BASE			0x320

#define MDSS_MDP_REG_VIG_CSC_10_BASE			0x1A04
#define MDSS_MDP_REG_VIG_CSC_10_OP_MODE			0x1A00

#define MDSS_MDP_REG_VIG_HIST_CTL_BASE			0x2C4
#define MDSS_MDP_REG_VIG_HIST_DATA_BASE			0x2E0
#define MDSS_MDP_REG_VIG_HIST_LUT_BASE			0x2F0

#define MDSS_MDP_SCALE_FILTER_NEAREST		0x0
#define MDSS_MDP_SCALE_FILTER_BIL		0x1
#define MDSS_MDP_SCALE_FILTER_PCMN		0x2
#define MDSS_MDP_SCALE_FILTER_CA		0x3
#define MDSS_MDP_SCALEY_EN			BIT(1)
#define MDSS_MDP_SCALEX_EN			BIT(0)
#define MDSS_MDP_FMT_SOLID_FILL			0x4037FF

#define MDSS_MDP_INTF_EDP_SEL	(BIT(3) | BIT(1))
#define MDSS_MDP_INTF_HDMI_SEL	(BIT(25) | BIT(24))
#define MDSS_MDP_INTF_DSI0_SEL	BIT(8)
#define MDSS_MDP_INTF_DSI1_SEL	BIT(16)

enum mdss_mdp_mixer_intf_index {
	MDSS_MDP_INTF_LAYERMIXER0,
	MDSS_MDP_INTF_LAYERMIXER1,
	MDSS_MDP_INTF_LAYERMIXER2,
	MDSS_MDP_INTF_LAYERMIXER3,
	MDSS_MDP_INTF_MAX_LAYERMIXER,
};

enum mdss_mdp_mixer_wb_index {
	MDSS_MDP_WB_LAYERMIXER0,
	MDSS_MDP_WB_LAYERMIXER1,
	MDSS_MDP_WB_MAX_LAYERMIXER,
};

enum mdss_mdp_stage_index {
	MDSS_MDP_STAGE_UNUSED,
	MDSS_MDP_STAGE_BASE,
	MDSS_MDP_STAGE_0,
	MDSS_MDP_STAGE_1,
	MDSS_MDP_STAGE_2,
	MDSS_MDP_STAGE_3,
	MDSS_MDP_STAGE_4,
	MDSS_MDP_STAGE_5,
	MDSS_MDP_STAGE_6,
	MDSS_MDP_MAX_STAGE
};
#define MAX_PIPES_PER_STAGE	0x2
#define MAX_PIPES_PER_LM	(MDSS_MDP_MAX_STAGE*MAX_PIPES_PER_STAGE)

#define MDSS_MDP_REG_LM_OP_MODE				0x000
#define MDSS_MDP_REG_LM_OUT_SIZE			0x004
#define MDSS_MDP_REG_LM_BORDER_COLOR_0			0x008
#define MDSS_MDP_REG_LM_BORDER_COLOR_1			0x010

#define MDSS_MDP_REG_LM_BLEND_OFFSET(stage)	(0x20 + ((stage) * 0x30))
#define MDSS_MDP_REG_LM_BLEND_OP			0x00
#define MDSS_MDP_REG_LM_BLEND_FG_ALPHA			0x04
#define MDSS_MDP_REG_LM_BLEND_BG_ALPHA			0x08
#define MDSS_MDP_REG_LM_BLEND_FG_TRANSP_LOW0		0x0C
#define MDSS_MDP_REG_LM_BLEND_FG_TRANSP_LOW1		0x10
#define MDSS_MDP_REG_LM_BLEND_FG_TRANSP_HIGH0		0x14
#define MDSS_MDP_REG_LM_BLEND_FG_TRANSP_HIGH1		0x18
#define MDSS_MDP_REG_LM_BLEND_BG_TRANSP_LOW0		0x1C
#define MDSS_MDP_REG_LM_BLEND_BG_TRANSP_LOW1		0x20
#define MDSS_MDP_REG_LM_BLEND_BG_TRANSP_HIGH0		0x24
#define MDSS_MDP_REG_LM_BLEND_BG_TRANSP_HIGH1		0x28
#define MDSS_MDP_REG_LM_BLEND_STAGE4	0x150

#define MDSS_MDP_REG_LM_CURSOR_IMG_SIZE			0xE0
#define MDSS_MDP_REG_LM_CURSOR_SIZE			0xE4
#define MDSS_MDP_REG_LM_CURSOR_XY			0xE8
#define MDSS_MDP_REG_LM_CURSOR_STRIDE			0xDC
#define MDSS_MDP_REG_LM_CURSOR_FORMAT			0xEC
#define MDSS_MDP_REG_LM_CURSOR_BASE_ADDR		0xF0
#define MDSS_MDP_REG_LM_CURSOR_START_XY			0xF4
#define MDSS_MDP_REG_LM_CURSOR_BLEND_CONFIG		0xF8
#define MDSS_MDP_REG_LM_CURSOR_BLEND_PARAM		0xFC
#define MDSS_MDP_REG_LM_CURSOR_BLEND_TRANSP_LOW0	0x100
#define MDSS_MDP_REG_LM_CURSOR_BLEND_TRANSP_LOW1	0x104
#define MDSS_MDP_REG_LM_CURSOR_BLEND_TRANSP_HIGH0	0x108
#define MDSS_MDP_REG_LM_CURSOR_BLEND_TRANSP_HIGH1	0x10C

#define MDSS_MDP_REG_LM_GC_LUT_BASE	0x110

#define MDSS_MDP_LM_BORDER_COLOR		(1 << 24)
#define MDSS_MDP_LM_CURSOR_OUT			(1 << 25)
#define MDSS_MDP_BLEND_FG_ALPHA_FG_CONST	(0 << 0)
#define MDSS_MDP_BLEND_FG_ALPHA_BG_CONST	(1 << 0)
#define MDSS_MDP_BLEND_FG_ALPHA_FG_PIXEL	(2 << 0)
#define MDSS_MDP_BLEND_FG_ALPHA_BG_PIXEL	(3 << 0)
#define MDSS_MDP_BLEND_FG_INV_ALPHA		(1 << 2)
#define MDSS_MDP_BLEND_FG_MOD_ALPHA		(1 << 3)
#define MDSS_MDP_BLEND_FG_INV_MOD_ALPHA		(1 << 4)
#define MDSS_MDP_BLEND_FG_TRANSP_EN		(1 << 5)
#define MDSS_MDP_BLEND_BG_ALPHA_FG_CONST	(0 << 8)
#define MDSS_MDP_BLEND_BG_ALPHA_BG_CONST	(1 << 8)
#define MDSS_MDP_BLEND_BG_ALPHA_FG_PIXEL	(2 << 8)
#define MDSS_MDP_BLEND_BG_ALPHA_BG_PIXEL	(3 << 8)
#define MDSS_MDP_BLEND_BG_INV_ALPHA		(1 << 10)
#define MDSS_MDP_BLEND_BG_MOD_ALPHA		(1 << 11)
#define MDSS_MDP_BLEND_BG_INV_MOD_ALPHA		(1 << 12)
#define MDSS_MDP_BLEND_BG_TRANSP_EN		(1 << 13)

enum mdss_mdp_writeback_index {
	MDSS_MDP_WRITEBACK0,
	MDSS_MDP_WRITEBACK1,
	MDSS_MDP_WRITEBACK2,
	MDSS_MDP_WRITEBACK3,
	MDSS_MDP_WRITEBACK4,
	MDSS_MDP_MAX_WRITEBACK
};

#define MDSS_MDP_REG_WB_DST_FORMAT			0x000
#define MDSS_MDP_REG_WB_DST_OP_MODE			0x004
#define MDSS_MDP_REG_WB_DST_PACK_PATTERN		0x008
#define MDSS_MDP_REG_WB_DST0_ADDR			0x00C
#define MDSS_MDP_REG_WB_DST1_ADDR			0x010
#define MDSS_MDP_REG_WB_DST2_ADDR			0x014
#define MDSS_MDP_REG_WB_DST3_ADDR			0x018
#define MDSS_MDP_REG_WB_DST_YSTRIDE0			0x01C
#define MDSS_MDP_REG_WB_DST_YSTRIDE1			0x020
#define MDSS_MDP_REG_WB_DST_YSTRIDE1			0x020
#define MDSS_MDP_REG_WB_DST_DITHER_BITDEPTH		0x024
#define MDSS_MDP_REG_WB_DST_MATRIX_ROW0			0x030
#define MDSS_MDP_REG_WB_DST_MATRIX_ROW1			0x034
#define MDSS_MDP_REG_WB_DST_MATRIX_ROW2			0x038
#define MDSS_MDP_REG_WB_DST_MATRIX_ROW3			0x03C
#define MDSS_MDP_REG_WB_DST_WRITE_CONFIG		0x048
#define MDSS_MDP_REG_WB_ROTATION_DNSCALER		0x050
#define MDSS_MDP_REG_WB_ROTATOR_PIPE_DOWNSCALER		0x054
#define MDSS_MDP_REG_WB_N16_INIT_PHASE_X_C03		0x060
#define MDSS_MDP_REG_WB_N16_INIT_PHASE_X_C12		0x064
#define MDSS_MDP_REG_WB_N16_INIT_PHASE_Y_C03		0x068
#define MDSS_MDP_REG_WB_N16_INIT_PHASE_Y_C12		0x06C
#define MDSS_MDP_REG_WB_OUT_SIZE			0x074
#define MDSS_MDP_REG_WB_ALPHA_X_VALUE			0x078
#define MDSS_MDP_REG_WB_DANGER_LUT			0x084
#define MDSS_MDP_REG_WB_SAFE_LUT			0x088
#define MDSS_MDP_REG_WB_CREQ_LUT			0x08c
#define MDSS_MDP_REG_WB_QOS_CTRL			0x090
#define MDSS_MDP_REG_WB_CSC_BASE			0x260
#define MDSS_MDP_REG_WB_DST_ADDR_SW_STATUS		0x2B0
#define MDSS_MDP_REG_WB_CDP_CTRL			0x2B4

#define MDSS_MDP_MAX_AD_AL	65535
#define MDSS_MDP_MAX_AD_STR	255
#define MDSS_MDP_AD_BL_SCALE	4095

#define MDSS_MDP_REG_AD_BYPASS				0x000
#define MDSS_MDP_REG_AD_CTRL_0				0x004
#define MDSS_MDP_REG_AD_CTRL_1				0x008
#define MDSS_MDP_REG_AD_FRAME_SIZE			0x00C
#define MDSS_MDP_REG_AD_CON_CTRL_0			0x010
#define MDSS_MDP_REG_AD_CON_CTRL_1			0x014
#define MDSS_MDP_REG_AD_STR_MAN				0x018
#define MDSS_MDP_REG_AD_VAR				0x01C
#define MDSS_MDP_REG_AD_DITH				0x020
#define MDSS_MDP_REG_AD_DITH_CTRL			0x024
#define MDSS_MDP_REG_AD_AMP_LIM				0x028
#define MDSS_MDP_REG_AD_SLOPE				0x02C
#define MDSS_MDP_REG_AD_BW_LVL				0x030
#define MDSS_MDP_REG_AD_LOGO_POS			0x034
#define MDSS_MDP_REG_AD_LUT_FI				0x038
#define MDSS_MDP_REG_AD_LUT_CC				0x07C
#define MDSS_MDP_REG_AD_STR_LIM				0x0C8
#define MDSS_MDP_REG_AD_CALIB_AB			0x0CC
#define MDSS_MDP_REG_AD_CALIB_CD			0x0D0
#define MDSS_MDP_REG_AD_MODE_SEL			0x0D4
#define MDSS_MDP_REG_AD_TFILT_CTRL			0x0D8
#define MDSS_MDP_REG_AD_BL_MINMAX			0x0DC
#define MDSS_MDP_REG_AD_BL				0x0E0
#define MDSS_MDP_REG_AD_BL_MAX				0x0E8
#define MDSS_MDP_REG_AD_AL				0x0EC
#define MDSS_MDP_REG_AD_AL_MIN				0x0F0
#define MDSS_MDP_REG_AD_AL_FILT				0x0F4
#define MDSS_MDP_REG_AD_CFG_BUF				0x0F8
#define MDSS_MDP_REG_AD_LUT_AL				0x100
#define MDSS_MDP_REG_AD_TARG_STR			0x144
#define MDSS_MDP_REG_AD_START_CALC			0x148
#define MDSS_MDP_REG_AD_STR_OUT				0x14C
#define MDSS_MDP_REG_AD_BL_OUT				0x154
#define MDSS_MDP_REG_AD_CALC_DONE			0x158
#define MDSS_MDP_REG_AD_FRAME_END			0x15C
#define MDSS_MDP_REG_AD_PROCS_END			0x160
#define MDSS_MDP_REG_AD_FRAME_START			0x164
#define MDSS_MDP_REG_AD_PROCS_START			0x168
#define MDSS_MDP_REG_AD_TILE_CTRL			0x16C

enum mdss_mdp_dspp_index {
	MDSS_MDP_DSPP0,
	MDSS_MDP_DSPP1,
	MDSS_MDP_DSPP2,
	MDSS_MDP_DSPP3,
	MDSS_MDP_MAX_DSPP
};

#define MDSS_MDP_REG_DSPP_OP_MODE			0x000
#define MDSS_MDP_REG_DSPP_PCC_BASE			0x030
#define MDSS_MDP_REG_DSPP_DITHER_DEPTH			0x150
#define MDSS_MDP_REG_DSPP_HIST_CTL_BASE			0x210
#define MDSS_MDP_REG_DSPP_HIST_DATA_BASE		0x22C
#define MDSS_MDP_REG_DSPP_HIST_LUT_BASE			0x230
#define MDSS_MDP_REG_DSPP_PA_BASE			0x238
#define MDSS_MDP_REG_DSPP_SIX_ZONE_BASE			0x248
#define MDSS_MDP_REG_DSPP_GAMUT_BASE			0x2DC
#define MDSS_MDP_REG_DSPP_GC_BASE			0x2B0

#define MDSS_MDP_DSPP_OP_IGC_LUT_EN			BIT(0)
#define MDSS_MDP_DSPP_OP_PA_SAT_ZERO_EXP_EN		BIT(1)
#define MDSS_MDP_DSPP_OP_PA_MEM_PROTECT_EN		BIT(2)
#define MDSS_MDP_DSPP_OP_PCC_EN				BIT(4)
#define MDSS_MDP_DSPP_OP_PA_MEM_COL_SKIN_MASK		BIT(5)
#define MDSS_MDP_DSPP_OP_PA_MEM_COL_FOL_MASK		BIT(6)
#define MDSS_MDP_DSPP_OP_PA_MEM_COL_SKY_MASK		BIT(7)
#define MDSS_MDP_DSPP_OP_DST_DITHER_EN			BIT(8)
#define MDSS_MDP_DSPP_OP_HIST_EN			BIT(16)
#define MDSS_MDP_DSPP_OP_HIST_LUTV_EN			BIT(19)
#define MDSS_MDP_DSPP_OP_PA_EN				BIT(20)
#define MDSS_MDP_DSPP_OP_ARGC_LUT_EN			BIT(22)
#define MDSS_MDP_DSPP_OP_GAMUT_EN			BIT(23)
#define MDSS_MDP_DSPP_OP_GAMUT_PCC_ORDER		BIT(24)
#define MDSS_MDP_DSPP_OP_PA_HUE_MASK			BIT(25)
#define MDSS_MDP_DSPP_OP_PA_SAT_MASK			BIT(26)
#define MDSS_MDP_DSPP_OP_PA_VAL_MASK			BIT(27)
#define MDSS_MDP_DSPP_OP_PA_CONT_MASK			BIT(28)
#define MDSS_MDP_DSPP_OP_PA_SIX_ZONE_HUE_MASK		BIT(29)
#define MDSS_MDP_DSPP_OP_PA_SIX_ZONE_SAT_MASK		BIT(30)
#define MDSS_MDP_DSPP_OP_PA_SIX_ZONE_VAL_MASK		BIT(31)

#define MDSS_MDP_REG_INTF_TIMING_ENGINE_EN		0x000
#define MDSS_MDP_REG_INTF_CONFIG			0x004
#define MDSS_MDP_REG_INTF_HSYNC_CTL			0x008
#define MDSS_MDP_REG_INTF_VSYNC_PERIOD_F0		0x00C
#define MDSS_MDP_REG_INTF_VSYNC_PERIOD_F1		0x010
#define MDSS_MDP_REG_INTF_VSYNC_PULSE_WIDTH_F0		0x014
#define MDSS_MDP_REG_INTF_VSYNC_PULSE_WIDTH_F1		0x018
#define MDSS_MDP_REG_INTF_DISPLAY_V_START_F0		0x01C
#define MDSS_MDP_REG_INTF_DISPLAY_V_START_F1		0x020
#define MDSS_MDP_REG_INTF_DISPLAY_V_END_F0		0x024
#define MDSS_MDP_REG_INTF_DISPLAY_V_END_F1		0x028
#define MDSS_MDP_REG_INTF_ACTIVE_V_START_F0		0x02C
#define MDSS_MDP_REG_INTF_ACTIVE_V_START_F1		0x030
#define MDSS_MDP_REG_INTF_ACTIVE_V_END_F0		0x034
#define MDSS_MDP_REG_INTF_ACTIVE_V_END_F1		0x038
#define MDSS_MDP_REG_INTF_DISPLAY_HCTL			0x03C
#define MDSS_MDP_REG_INTF_ACTIVE_HCTL			0x040
#define MDSS_MDP_REG_INTF_BORDER_COLOR			0x044
#define MDSS_MDP_REG_INTF_UNDERFLOW_COLOR		0x048
#define MDSS_MDP_REG_INTF_HSYNC_SKEW			0x04C
#define MDSS_MDP_REG_INTF_POLARITY_CTL			0x050
#define MDSS_MDP_REG_INTF_TEST_CTL			0x054
#define MDSS_MDP_REG_INTF_TP_COLOR0			0x058
#define MDSS_MDP_REG_INTF_TP_COLOR1			0x05C
#define MDSS_MDP_REG_INTF_FRAME_LINE_COUNT_EN           0x0A8
#define MDSS_MDP_REG_INTF_FRAME_COUNT                   0x0AC
#define MDSS_MDP_REG_INTF_LINE_COUNT                    0x0B0

#define MDSS_MDP_REG_INTF_DEFLICKER_CONFIG		0x0F0
#define MDSS_MDP_REG_INTF_DEFLICKER_STRNG_COEFF		0x0F4
#define MDSS_MDP_REG_INTF_DEFLICKER_WEAK_COEFF		0x0F8

#define MDSS_MDP_REG_INTF_DSI_CMD_MODE_TRIGGER_EN	0x084
#define MDSS_MDP_REG_INTF_PANEL_FORMAT			0x090
#define MDSS_MDP_REG_INTF_TPG_ENABLE			0x100
#define MDSS_MDP_REG_INTF_TPG_MAIN_CONTROL		0x104
#define MDSS_MDP_REG_INTF_TPG_VIDEO_CONFIG		0x108
#define MDSS_MDP_REG_INTF_TPG_COMPONENT_LIMITS		0x10C
#define MDSS_MDP_REG_INTF_TPG_RECTANGLE			0x110
#define MDSS_MDP_REG_INTF_TPG_INITIAL_VALUE		0x114
#define MDSS_MDP_REG_INTF_TPG_BLK_WHITE_PATTERN_FRAMES	0x118
#define MDSS_MDP_REG_INTF_TPG_RGB_MAPPING		0x11C
#define MDSS_MDP_REG_INTF_PROG_FETCH_START		0x170
#define MDSS_MDP_REG_INTF_INTR_EN			0x1C0
#define MDSS_MDP_REG_INTF_INTR_STATUS			0x1C4
#define MDSS_MDP_REG_INTF_INTR_CLEAR			0x1C8
#define MDSS_MDP_REG_INTF_PROG_LINE_INTR_CONF		0x250
#define MDSS_MDP_REG_INTF_VBLANK_END_CONF		0x264
#define MDSS_MDP_REG_INTF_RGB_INTF_CTRL			0x268
#define MDSS_MDP_REG_INTF_AVR_CONTROL			0x270
#define MDSS_MDP_REG_INTF_AVR_MODE			0x274
#define MDSS_MDP_REG_INTF_AVR_TRIGGER			0x278
#define MDSS_MDP_REG_INTF_AVR_VTOTAL			0x27C

#define MDSS_MDP_REG_INTF_FRAME_LINE_COUNT_EN		0x0A8
#define MDSS_MDP_REG_INTF_FRAME_COUNT			0x0AC
#define MDSS_MDP_REG_INTF_LINE_COUNT			0x0B0
#define MDSS_MDP_PANEL_FORMAT_RGB888			0x213F
#define MDSS_MDP_PANEL_FORMAT_RGB666			0x212A

#define MDSS_MDP_REG_DSI_ULP_CLAMP_VALUE		0x064

#define MDSS_MDP_PANEL_FORMAT_PACK_ALIGN_MSB		BIT(7)

enum mdss_mdp_pingpong_index {
	MDSS_MDP_PINGPONG0,
	MDSS_MDP_PINGPONG1,
	MDSS_MDP_PINGPONG2,
	MDSS_MDP_PINGPONG3,
	MDSS_MDP_MAX_PINGPONG
};

#define MDSS_MDP_REG_PP_TEAR_CHECK_EN			0x000
#define MDSS_MDP_REG_PP_SYNC_CONFIG_VSYNC		0x004
#define MDSS_MDP_REG_PP_SYNC_CONFIG_HEIGHT		0x008
#define MDSS_MDP_REG_PP_SYNC_WRCOUNT			0x00C
#define MDSS_MDP_REG_PP_VSYNC_INIT_VAL			0x010
#define MDSS_MDP_REG_PP_INT_COUNT_VAL			0x014
#define MDSS_MDP_REG_PP_SYNC_THRESH			0x018
#define MDSS_MDP_REG_PP_START_POS			0x01C
#define MDSS_MDP_REG_PP_RD_PTR_IRQ			0x020
#define MDSS_MDP_REG_PP_WR_PTR_IRQ			0x024
#define MDSS_MDP_REG_PP_OUT_LINE_COUNT			0x028
#define MDSS_MDP_REG_PP_LINE_COUNT			0x02C
#define MDSS_MDP_REG_PP_AUTOREFRESH_CONFIG		0x030

#define MDSS_MDP_REG_PP_FBC_MODE			0x034
#define MDSS_MDP_REG_PP_FBC_BUDGET_CTL			0x038
#define MDSS_MDP_REG_PP_FBC_LOSSY_MODE			0x03C
#define MDSS_MDP_REG_PP_DSC_MODE			0x0a0
#define MDSS_MDP_REG_PP_DCE_DATA_IN_SWAP		0x0ac
#define MDSS_MDP_REG_PP_DCE_DATA_OUT_SWAP		0x0c8

#define MDSS_MDP_DSC_0_OFFSET				0x80000
#define MDSS_MDP_DSC_1_OFFSET				0x80400

#define MDSS_MDP_REG_DSC_COMMON_MODE			0x000
#define MDSS_MDP_REG_DSC_ENC				0x004
#define MDSS_MDP_REG_DSC_PICTURE			0x008
#define MDSS_MDP_REG_DSC_SLICE				0x00c
#define MDSS_MDP_REG_DSC_CHUNK_SIZE			0x010
#define MDSS_MDP_REG_DSC_DELAY				0x014
#define MDSS_MDP_REG_DSC_SCALE_INITIAL			0x018
#define MDSS_MDP_REG_DSC_SCALE_DEC_INTERVAL		0x01c
#define MDSS_MDP_REG_DSC_SCALE_INC_INTERVAL		0x020
#define MDSS_MDP_REG_DSC_FIRST_LINE_BPG_OFFSET		0x024
#define MDSS_MDP_REG_DSC_BPG_OFFSET			0x028
#define MDSS_MDP_REG_DSC_DSC_OFFSET			0x02c
#define MDSS_MDP_REG_DSC_FLATNESS			0x030
#define MDSS_MDP_REG_DSC_RC_MODEL_SIZE			0x034
#define MDSS_MDP_REG_DSC_RC				0x038
#define MDSS_MDP_REG_DSC_RC_BUF_THRESH			0x03c
#define MDSS_MDP_REG_DSC_RANGE_MIN_QP			0x074
#define MDSS_MDP_REG_DSC_RANGE_MAX_QP			0x0b0
#define MDSS_MDP_REG_DSC_RANGE_BPG_OFFSET		0x0ec

#define MDSS_MDP_REG_SMP_ALLOC_W0			0x00080
#define MDSS_MDP_REG_SMP_ALLOC_R0			0x00130

#define MDSS_MDP_UP_MISR_SEL			0x2A0
#define MDSS_MDP_UP_MISR_CTRL_MDP		0x2A4
#define MDSS_MDP_UP_MISR_SIGN_MDP		0x2A8
#define MDSS_MDP_UP_MISR_LMIX_SEL_OFFSET	0x4C

#define MDSS_MDP_LP_MISR_SEL			0x350
#define MDSS_MDP_LP_MISR_CTRL_MDP		0x354
#define MDSS_MDP_LP_MISR_CTRL_HDMI		0x358
#define MDSS_MDP_LP_MISR_CTRL_EDP		0x35C
#define MDSS_MDP_LP_MISR_CTRL_DSI0		0x360
#define MDSS_MDP_LP_MISR_CTRL_DSI1		0x364

#define MDSS_MDP_LP_MISR_SIGN_MDP		0x368
#define MDSS_MDP_LP_MISR_SIGN_EDP		0x36C
#define MDSS_MDP_LP_MISR_SIGN_HDMI		0x370
#define MDSS_MDP_LP_MISR_SIGN_DSI0		0x374
#define MDSS_MDP_LP_MISR_SIGN_DSI1		0x378

#define MDSS_MDP_MISR_CTRL_FRAME_COUNT_MASK	0xFF
#define MDSS_MDP_MISR_CTRL_ENABLE		BIT(8)
#define MDSS_MDP_MISR_CTRL_STATUS		BIT(9)
#define MDSS_MDP_MISR_CTRL_STATUS_CLEAR	BIT(10)
#define MDSS_MDP_LP_MISR_CTRL_FREE_RUN_MASK	BIT(31)

#define MDSS_MDP_LP_MISR_SEL_LMIX0_BLEND	0x08
#define MDSS_MDP_LP_MISR_SEL_LMIX0_GC		0x09
#define MDSS_MDP_LP_MISR_SEL_LMIX1_BLEND	0x0A
#define MDSS_MDP_LP_MISR_SEL_LMIX1_GC		0x0B
#define MDSS_MDP_LP_MISR_SEL_LMIX2_BLEND	0x0C
#define MDSS_MDP_LP_MISR_SEL_LMIX2_GC		0x0D
#define MDSS_MDP_LP_MISR_SEL_LMIX3_BLEND	0x0E
#define MDSS_MDP_LP_MISR_SEL_LMIX3_GC		0x0F
#define MDSS_MDP_LP_MISR_SEL_LMIX4_BLEND	0x10
#define MDSS_MDP_LP_MISR_SEL_LMIX4_GC		0x11

#define MDSS_MDP_LAYER_MIXER_MISR_CTRL		0x380
#define MDSS_MDP_LAYER_MIXER_MISR_SIGNATURE	\
		(MDSS_MDP_LAYER_MIXER_MISR_CTRL + 0x4)

#define MDSS_MDP_INTF_MISR_CTRL		0x180
#define MDSS_MDP_INTF_MISR_SIGNATURE		(MDSS_MDP_INTF_MISR_CTRL + 0x4)
#define MDSS_MDP_INTF_CMD_MISR_CTRL		(MDSS_MDP_INTF_MISR_CTRL + 0x8)
#define MDSS_MDP_INTF_CMD_MISR_SIGNATURE	(MDSS_MDP_INTF_MISR_CTRL + 0xC)

#define MDSS_MDP_REG_CDM_CSC_10_OPMODE                  0x000
#define MDSS_MDP_REG_CDM_CSC_10_BASE                    0x004

#define MDSS_MDP_REG_CDM_CDWN2_OP_MODE                  0x100
#define MDSS_MDP_REG_CDM_CDWN2_CLAMP_OUT                0x104
#define MDSS_MDP_REG_CDM_CDWN2_PARAMS_3D_0              0x108
#define MDSS_MDP_REG_CDM_CDWN2_PARAMS_3D_1              0x10C
#define MDSS_MDP_REG_CDM_CDWN2_COEFF_COSITE_H_0         0x110
#define MDSS_MDP_REG_CDM_CDWN2_COEFF_COSITE_H_1         0x114
#define MDSS_MDP_REG_CDM_CDWN2_COEFF_COSITE_H_2         0x118
#define MDSS_MDP_REG_CDM_CDWN2_COEFF_OFFSITE_H_0        0x11C
#define MDSS_MDP_REG_CDM_CDWN2_COEFF_OFFSITE_H_1        0x120
#define MDSS_MDP_REG_CDM_CDWN2_COEFF_OFFSITE_H_2        0x124
#define MDSS_MDP_REG_CDM_CDWN2_COEFF_COSITE_V           0x128
#define MDSS_MDP_REG_CDM_CDWN2_COEFF_OFFSITE_V          0x12C
#define MDSS_MDP_REG_CDM_CDWN2_OUT_SIZE                 0x130

#define MDSS_MDP_REG_CDM_HDMI_PACK_OP_MODE              0x200

#define MDSS_MDP_DSPP_DEBUGBUS_STATUS                   0x34C

/* Following offsets are with respect to MDP base */
#define MDSS_MDP_HDMI_DP_CORE_SELECT                    0x408
#define MDSS_MDP_MDP_OUT_CTL_0                          0x410
#define MDSS_MDP_INTF_CMD_MISR_CTRL		(MDSS_MDP_INTF_MISR_CTRL + 0x8)
#define MDSS_MDP_INTF_CMD_MISR_SIGNATURE	(MDSS_MDP_INTF_MISR_CTRL + 0xC)
/* following offsets are with respect to MDP VBIF base */
#define MMSS_VBIF_CLKON			0x4
#define MMSS_VBIF_RD_LIM_CONF			0x0B0
#define MMSS_VBIF_WR_LIM_CONF			0x0C0
#define MDSS_VBIF_WRITE_GATHER_EN		0x0AC

#define MMSS_VBIF_SRC_ERR		0x194
#define MMSS_VBIF_ERR_INFO		0x1A0
#define MMSS_VBIF_XIN_HALT_CTRL0	0x200
#define MMSS_VBIF_XIN_HALT_CTRL1	0x204
#define MMSS_VBIF_AXI_HALT_CTRL0	0x208
#define MMSS_VBIF_AXI_HALT_CTRL1	0x20C
#define MMSS_VBIF_TEST_BUS_OUT_CTRL	0x210
#define MMSS_VBIF_TEST_BUS_OUT		0x230

#define MDSS_VBIF_QOS_REMAP_BASE	0x020
#define MDSS_VBIF_QOS_REMAP_ENTRIES	0x4

#define MDSS_VBIF_QOS_RP_REMAP_BASE	0x550
#define MDSS_VBIF_QOS_LVL_REMAP_BASE	0x570

#define MDSS_VBIF_FIXED_SORT_EN	0x30
#define MDSS_VBIF_FIXED_SORT_SEL0	0x34

#define MDSS_MDP_REG_TRAFFIC_SHAPER_EN			BIT(31)
#define MDSS_MDP_REG_TRAFFIC_SHAPER_RD_CLIENT(num)	(0x030 + (num * 4))
#define MDSS_MDP_REG_TRAFFIC_SHAPER_WR_CLIENT(num)	(0x060 + (num * 4))
#define MDSS_MDP_REG_TRAFFIC_SHAPER_FIXPOINT_FACTOR	4

#define MDSS_MDP_REG_SPLIT_LINK				0x00060
#define MDSS_MDP_REG_SPLIT_LINK_LEFT_LINK_EN		BIT(1)
#define MDSS_MDP_REG_SPLIT_LINK_RIGHT_LINK_EN		BIT(2)

#endif
