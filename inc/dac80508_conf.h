/***********************************************************************************
  * @file    dac80508_conf.h
  * @brief   C Library for configuring the DACx0501/2/4/8 DAC on STM32 from SPI.
  *          Forked from MCP3564 library of Simon Burkhardt.
  *          Clock Polarity (CPOL) == Low & Clock Phase (CPHA) == 2 Edge
  * @version 0.1
  * @date    Jul 28, 2023
  * @license Apache 2.0
  * @author  Mithat Can Ozin & Mesut Soylemez
  *
  *          Istanbul Technical University
  *
  * @see     https://www.ti.com/product/DAC80508
************************************************************************************
*/

#ifndef INC_DAC80508_CONF_H_
#define INC_DAC80508_CONF_H_

#define DAC80508_USERCONF_SYNC\
	(DAC80508_SYNC_DAC7_BRDCAST_EN_ON | DAC80508_SYNC_DAC6_BRDCAST_EN_ON | DAC80508_SYNC_DAC5_BRDCAST_EN_ON | DAC80508_SYNC_DAC4_BRDCAST_EN_ON\
	| DAC80508_SYNC_DAC3_BRDCAST_EN_ON | DAC80508_SYNC_DAC2_BRDCAST_EN_ON | DAC80508_SYNC_DAC1_BRDCAST_EN_ON | DAC80508_SYNC_DAC0_BRDCAST_EN_ON\
	| DAC80508_SYNC_DAC7_SYNC_EN_OFF | DAC80508_SYNC_DAC6_SYNC_EN_OFF | DAC80508_SYNC_DAC5_SYNC_EN_OFF | DAC80508_SYNC_DAC4_SYNC_EN_OFF\
	| DAC80508_SYNC_DAC3_SYNC_EN_OFF | DAC80508_SYNC_DAC2_SYNC_EN_OFF | DAC80508_SYNC_DAC1_SYNC_EN_OFF | DAC80508_SYNC_DAC0_SYNC_EN_OFF)
#define DAC80508_USERCONF_CONFIG\
	(DAC80508_CONFIG_ALM_SEL_CRC | DAC80508_CONFIG_ALM_EN_OFF | DAC80508_CONFIG_CRC_EN_OFF | DAC80508_CONFIG_FSDO_OFF\
	| DAC80508_CONFIG_DSDO_OFF | DAC80508_CONFIG_REF_PWDWN_INT | DAC80508_CONFIG_DAC7_PWDWN_OFF | DAC80508_CONFIG_DAC6_PWDWN_OFF\
	| DAC80508_CONFIG_DAC5_PWDWN_OFF | DAC80508_CONFIG_DAC4_PWDWN_OFF | DAC80508_CONFIG_DAC3_PWDWN_OFF | DAC80508_CONFIG_DAC2_PWDWN_OFF\
	| DAC80508_CONFIG_DAC1_PWDWN_OFF| DAC80508_CONFIG_DAC0_PWDWN_OFF)
#define DAC80508_USERCONF_GAIN\
	(DAC80508_GAIN_REFDIV_EN_2 | DAC80508_GAIN_BUFF7_GAIN_2 | DAC80508_GAIN_BUFF6_GAIN_2 | DAC80508_GAIN_BUFF5_GAIN_2\
	| DAC80508_GAIN_BUFF4_GAIN_2 | DAC80508_GAIN_BUFF3_GAIN_2 | DAC80508_GAIN_BUFF2_GAIN_2| DAC80508_GAIN_BUFF1_GAIN_2\
	| DAC80508_GAIN_BUFF0_GAIN_2)
#define DAC80508_USERCONF_TRIGGER (DAC80508_TRIGGER_SOFT_LDAC_OFF | DAC80508_TRIGGER_SOFT_RESET_OFF)

#endif /* INC_DAC80508_CONF_H_ */
