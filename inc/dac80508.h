/***********************************************************************************
  * @file    dac80508.h
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

#ifndef DAC80508_H_
#define DAC80508_H_

#ifdef __cplusplus
 extern "C" {
#endif

 /* Includes ------------------------------------------------------------------*/
#include "main.h"

 /* Private macros ------------------------------------------------------------*/
 /* Exported types ------------------------------------------------------------*/
 /* Exported constants --------------------------------------------------------*/
 /* Exported functions prototypes ---------------------------------------------*/
void DAC80508_init(SPI_HandleTypeDef *hspi);
void DAC80508_reset(SPI_HandleTypeDef *hspi);
uint16_t DAC80508_read_DEV_ID(SPI_HandleTypeDef *hspi);
uint16_t DAC80508_read_SYNC(SPI_HandleTypeDef *hspi);
uint16_t DAC80508_read_CONFIG(SPI_HandleTypeDef *hspi);
uint16_t DAC80508_read_GAIN(SPI_HandleTypeDef *hspi);
uint16_t DAC80508_read_TRIGGER(SPI_HandleTypeDef *hspi);
uint16_t DAC80508_read_DAC(SPI_HandleTypeDef *hspi, uint8_t ch);
void DAC80508_write_DAC(SPI_HandleTypeDef *hspi, uint8_t ch, uint16_t val);

 /* Private defines -----------------------------------------------------------*/
#define DAC80508_CHIP_SELECT_GPIO_Pin  (SPI1_CS_Pin)
#define DAC80508_CHIP_SELECT_GPIO_Port (SPI1_CS_GPIO_Port)
#define DAC80508_HAL_TIMEOUT           (10)

 /* @note for testing */

// USEFUL MASKS FOR DAC COMMUNICATION
#define DAC80508_READ_COMMAND_MASK        (0x1) // 0b1 // Read command
#define DAC80508_READ_COMMAND             (DAC80508_READ_COMMAND_MASK << 7)
#define DAC80508_WRITE_COMMAND_MASK       (0x0) // 0b0 // Write command
#define DAC80508_WRITE_COMMAND            (DAC80508_WRITE_COMMAND_MASK << 7)

#define DAC80508_DEV_ID_ADDR            (0x01)
#define DAC80508_DEV_ID_READ            DAC80508_DEV_ID_ADDR | DAC80508_READ_COMMAND
#define _DAC80508_DEV_ID_RES0_POS        (15)
#define _DAC80508_DEV_ID_RSL_POS         (12)
#define _DAC80508_DEV_ID_CH_POS          (8)
#define _DAC80508_DEV_ID_RST_POS         (7)
#define _DAC80508_DEV_ID_RES1_POS        (2)
#define _DAC80508_DEV_ID_REV_POS         (0)

#define DAC80508_SYNC_ADDR                         (0x02)
#define DAC80508_SYNC_READ                         DAC80508_SYNC_ADDR | DAC80508_READ_COMMAND
#define DAC80508_SYNC_WRITE                        DAC80508_SYNC_ADDR | DAC80508_WRITE_COMMAND
#define _DAC80508_SYNC_DAC7_BRDCAST_EN_POS         (15)
#define DAC80508_SYNC_DAC7_BRDCAST_EN_ON           (0x01 << _DAC80508_SYNC_DAC7_BRDCAST_EN_POS)
#define DAC80508_SYNC_DAC7_BRDCAST_EN_OFF          (0x00 << _DAC80508_SYNC_DAC7_BRDCAST_EN_POS)
#define _DAC80508_SYNC_DAC6_BRDCAST_EN_POS         (14)
#define DAC80508_SYNC_DAC6_BRDCAST_EN_ON           (0x01 << _DAC80508_SYNC_DAC6_BRDCAST_EN_POS)
#define DAC80508_SYNC_DAC6_BRDCAST_EN_OFF          (0x00 << _DAC80508_SYNC_DAC6_BRDCAST_EN_POS)
#define _DAC80508_SYNC_DAC5_BRDCAST_EN_POS         (13)
#define DAC80508_SYNC_DAC5_BRDCAST_EN_ON           (0x01 << _DAC80508_SYNC_DAC5_BRDCAST_EN_POS)
#define DAC80508_SYNC_DAC5_BRDCAST_EN_OFF          (0x00 << _DAC80508_SYNC_DAC5_BRDCAST_EN_POS)
#define _DAC80508_SYNC_DAC4_BRDCAST_EN_POS         (12)
#define DAC80508_SYNC_DAC4_BRDCAST_EN_ON           (0x01 << _DAC80508_SYNC_DAC4_BRDCAST_EN_POS)
#define DAC80508_SYNC_DAC4_BRDCAST_EN_OFF          (0x00 << _DAC80508_SYNC_DAC4_BRDCAST_EN_POS)
#define _DAC80508_SYNC_DAC3_BRDCAST_EN_POS         (11)
#define DAC80508_SYNC_DAC3_BRDCAST_EN_ON           (0x01 << _DAC80508_SYNC_DAC3_BRDCAST_EN_POS)
#define DAC80508_SYNC_DAC3_BRDCAST_EN_OFF          (0x00 << _DAC80508_SYNC_DAC3_BRDCAST_EN_POS)
#define _DAC80508_SYNC_DAC2_BRDCAST_EN_POS         (10)
#define DAC80508_SYNC_DAC2_BRDCAST_EN_ON           (0x01 << _DAC80508_SYNC_DAC2_BRDCAST_EN_POS)
#define DAC80508_SYNC_DAC2_BRDCAST_EN_OFF          (0x00 << _DAC80508_SYNC_DAC2_BRDCAST_EN_POS)
#define _DAC80508_SYNC_DAC1_BRDCAST_EN_POS         (9)
#define DAC80508_SYNC_DAC1_BRDCAST_EN_ON           (0x01 << _DAC80508_SYNC_DAC1_BRDCAST_EN_POS)
#define DAC80508_SYNC_DAC1_BRDCAST_EN_OFF          (0x00 << _DAC80508_SYNC_DAC1_BRDCAST_EN_POS)
#define _DAC80508_SYNC_DAC0_BRDCAST_EN_POS         (8)
#define DAC80508_SYNC_DAC0_BRDCAST_EN_ON           (0x01 << _DAC80508_SYNC_DAC0_BRDCAST_EN_POS)
#define DAC80508_SYNC_DAC0_BRDCAST_EN_OFF          (0x00 << _DAC80508_SYNC_DAC0_BRDCAST_EN_POS)
#define _DAC80508_SYNC_DAC7_SYNC_EN_POS            (7)
#define DAC80508_SYNC_DAC7_SYNC_EN_ON              (0x01 << _DAC80508_SYNC_DAC7_SYNC_EN_POS)
#define DAC80508_SYNC_DAC7_SYNC_EN_OFF             (0x00 << _DAC80508_SYNC_DAC7_SYNC_EN_POS)
#define _DAC80508_SYNC_DAC6_SYNC_EN_POS            (6)
#define DAC80508_SYNC_DAC6_SYNC_EN_ON              (0x01 << _DAC80508_SYNC_DAC6_SYNC_EN_POS)
#define DAC80508_SYNC_DAC6_SYNC_EN_OFF             (0x00 << _DAC80508_SYNC_DAC6_SYNC_EN_POS)
#define _DAC80508_SYNC_DAC5_SYNC_EN_POS            (5)
#define DAC80508_SYNC_DAC5_SYNC_EN_ON              (0x01 << _DAC80508_SYNC_DAC5_SYNC_EN_POS)
#define DAC80508_SYNC_DAC5_SYNC_EN_OFF             (0x00 << _DAC80508_SYNC_DAC5_SYNC_EN_POS)
#define _DAC80508_SYNC_DAC4_SYNC_EN_POS            (4)
#define DAC80508_SYNC_DAC4_SYNC_EN_ON              (0x01 << _DAC80508_SYNC_DAC4_SYNC_EN_POS)
#define DAC80508_SYNC_DAC4_SYNC_EN_OFF             (0x00 << _DAC80508_SYNC_DAC4_SYNC_EN_POS)
#define _DAC80508_SYNC_DAC3_SYNC_EN_POS            (3)
#define DAC80508_SYNC_DAC3_SYNC_EN_ON              (0x01 << _DAC80508_SYNC_DAC3_SYNC_EN_POS)
#define DAC80508_SYNC_DAC3_SYNC_EN_OFF             (0x00 << _DAC80508_SYNC_DAC3_SYNC_EN_POS)
#define _DAC80508_SYNC_DAC2_SYNC_EN_POS            (2)
#define DAC80508_SYNC_DAC2_SYNC_EN_ON              (0x01 << _DAC80508_SYNC_DAC2_SYNC_EN_POS)
#define DAC80508_SYNC_DAC2_SYNC_EN_OFF             (0x00 << _DAC80508_SYNC_DAC2_SYNC_EN_POS)
#define _DAC80508_SYNC_DAC1_SYNC_EN_POS            (1)
#define DAC80508_SYNC_DAC1_SYNC_EN_ON              (0x01 << _DAC80508_SYNC_DAC1_SYNC_EN_POS)
#define DAC80508_SYNC_DAC1_SYNC_EN_OFF             (0x00 << _DAC80508_SYNC_DAC1_SYNC_EN_POS)
#define _DAC80508_SYNC_DAC0_SYNC_EN_POS            (0)
#define DAC80508_SYNC_DAC0_SYNC_EN_ON              (0x01 << _DAC80508_SYNC_DAC0_SYNC_EN_POS)
#define DAC80508_SYNC_DAC0_SYNC_EN_OFF             (0x00 << _DAC80508_SYNC_DAC0_SYNC_EN_POS)

#define DAC80508_CONFIG_ADDR               (0x03)
#define DAC80508_CONFIG_READ               DAC80508_CONFIG_ADDR | DAC80508_READ_COMMAND
#define DAC80508_CONFIG_WRITE              DAC80508_CONFIG_ADDR | DAC80508_WRITE_COMMAND
#define _DAC80508_CONFIG_ALM_SEL_POS       (13)
#define DAC80508_CONFIG_ALM_SEL_REF        (0x01 << _DAC80508_CONFIG_ALM_SEL_POS)
#define DAC80508_CONFIG_ALM_SEL_CRC        (0x00 << _DAC80508_CONFIG_ALM_SEL_POS)
#define _DAC80508_CONFIG_ALM_EN_POS        (12)
#define DAC80508_CONFIG_ALM_EN_ON          (0x01 << _DAC80508_CONFIG_ALM_EN_POS)
#define DAC80508_CONFIG_ALM_EN_OFF         (0x00 << _DAC80508_CONFIG_ALM_EN_POS)
#define _DAC80508_CONFIG_CRC_EN_POS        (11)
#define DAC80508_CONFIG_CRC_EN_ON          (0x01 << _DAC80508_CONFIG_CRC_EN_POS)
#define DAC80508_CONFIG_CRC_EN_OFF         (0x00 << _DAC80508_CONFIG_CRC_EN_POS)
#define _DAC80508_CONFIG_FSDO_POS          (10)
#define DAC80508_CONFIG_FSDO_ON            (0x01 << _DAC80508_CONFIG_FSDO_POS)
#define DAC80508_CONFIG_FSDO_OFF           (0x00 << _DAC80508_CONFIG_FSDO_POS)
#define _DAC80508_CONFIG_DSDO_POS          (9)
#define DAC80508_CONFIG_DSDO_ON            (0x01 << _DAC80508_CONFIG_DSDO_POS)
#define DAC80508_CONFIG_DSDO_OFF           (0x00 << _DAC80508_CONFIG_DSDO_POS)
#define _DAC80508_CONFIG_REF_PWDWN_POS     (8)
#define DAC80508_CONFIG_REF_PWDWN_EXT      (0x01 << _DAC80508_CONFIG_REF_PWDWN_POS)
#define DAC80508_CONFIG_REF_PWDWN_INT      (0x00 << _DAC80508_CONFIG_REF_PWDWN_POS)
#define _DAC80508_CONFIG_DAC7_PWDWN_POS    (7)
#define DAC80508_CONFIG_DAC7_PWDWN_ON      (0x01 << _DAC80508_CONFIG_DAC7_PWDWN_POS)
#define DAC80508_CONFIG_DAC7_PWDWN_OFF     (0x00 << _DAC80508_CONFIG_DAC7_PWDWN_POS)
#define _DAC80508_CONFIG_DAC6_PWDWN_POS    (6)
#define DAC80508_CONFIG_DAC6_PWDWN_ON      (0x01 << _DAC80508_CONFIG_DAC6_PWDWN_POS)
#define DAC80508_CONFIG_DAC6_PWDWN_OFF     (0x00 << _DAC80508_CONFIG_DAC6_PWDWN_POS)
#define _DAC80508_CONFIG_DAC5_PWDWN_POS    (5)
#define DAC80508_CONFIG_DAC5_PWDWN_ON      (0x01 << _DAC80508_CONFIG_DAC5_PWDWN_POS)
#define DAC80508_CONFIG_DAC5_PWDWN_OFF     (0x00 << _DAC80508_CONFIG_DAC5_PWDWN_POS)
#define _DAC80508_CONFIG_DAC4_PWDWN_POS    (4)
#define DAC80508_CONFIG_DAC4_PWDWN_ON      (0x01 << _DAC80508_CONFIG_DAC4_PWDWN_POS)
#define DAC80508_CONFIG_DAC4_PWDWN_OFF     (0x00 << _DAC80508_CONFIG_DAC4_PWDWN_POS)
#define _DAC80508_CONFIG_DAC3_PWDWN_POS    (3)
#define DAC80508_CONFIG_DAC3_PWDWN_ON      (0x01 << _DAC80508_CONFIG_DAC3_PWDWN_POS)
#define DAC80508_CONFIG_DAC3_PWDWN_OFF     (0x00 << _DAC80508_CONFIG_DAC3_PWDWN_POS)
#define _DAC80508_CONFIG_DAC2_PWDWN_POS    (2)
#define DAC80508_CONFIG_DAC2_PWDWN_ON      (0x01 << _DAC80508_CONFIG_DAC2_PWDWN_POS)
#define DAC80508_CONFIG_DAC2_PWDWN_OFF     (0x00 << _DAC80508_CONFIG_DAC2_PWDWN_POS)
#define _DAC80508_CONFIG_DAC1_PWDWN_POS    (1)
#define DAC80508_CONFIG_DAC1_PWDWN_ON      (0x01 << _DAC80508_CONFIG_DAC1_PWDWN_POS)
#define DAC80508_CONFIG_DAC1_PWDWN_OFF     (0x00 << _DAC80508_CONFIG_DAC1_PWDWN_POS)
#define _DAC80508_CONFIG_DAC0_PWDWN_POS    (0)
#define DAC80508_CONFIG_DAC0_PWDWN_ON      (0x01 << _DAC80508_CONFIG_DAC0_PWDWN_POS)
#define DAC80508_CONFIG_DAC0_PWDWN_OFF     (0x00 << _DAC80508_CONFIG_DAC0_PWDWN_POS)

#define DAC80508_GAIN_ADDR               (0x04)
#define DAC80508_GAIN_READ               DAC80508_GAIN_ADDR | DAC80508_READ_COMMAND
#define DAC80508_GAIN_WRITE              DAC80508_GAIN_ADDR | DAC80508_WRITE_COMMAND
#define _DAC80508_GAIN_REFDIV_EN_POS    (8)
#define DAC80508_GAIN_REFDIV_EN_2       (0x01 << _DAC80508_GAIN_REFDIV_EN_POS)
#define DAC80508_GAIN_REFDIV_EN_1       (0x00 << _DAC80508_GAIN_REFDIV_EN_POS)
#define _DAC80508_GAIN_BUFF7_GAIN_POS   (7)
#define DAC80508_GAIN_BUFF7_GAIN_2      (0x01 << _DAC80508_GAIN_BUFF7_GAIN_POS)
#define DAC80508_GAIN_BUFF7_GAIN_1      (0x00 << _DAC80508_GAIN_BUFF7_GAIN_POS)
#define _DAC80508_GAIN_BUFF6_GAIN_POS   (6)
#define DAC80508_GAIN_BUFF6_GAIN_2      (0x01 << _DAC80508_GAIN_BUFF6_GAIN_POS)
#define DAC80508_GAIN_BUFF6_GAIN_1      (0x00 << _DAC80508_GAIN_BUFF6_GAIN_POS)
#define _DAC80508_GAIN_BUFF5_GAIN_POS   (5)
#define DAC80508_GAIN_BUFF5_GAIN_2      (0x01 << _DAC80508_GAIN_BUFF5_GAIN_POS)
#define DAC80508_GAIN_BUFF5_GAIN_1      (0x00 << _DAC80508_GAIN_BUFF5_GAIN_POS)
#define _DAC80508_GAIN_BUFF4_GAIN_POS   (4)
#define DAC80508_GAIN_BUFF4_GAIN_2      (0x01 << _DAC80508_GAIN_BUFF4_GAIN_POS)
#define DAC80508_GAIN_BUFF4_GAIN_1      (0x00 << _DAC80508_GAIN_BUFF4_GAIN_POS)
#define _DAC80508_GAIN_BUFF3_GAIN_POS   (3)
#define DAC80508_GAIN_BUFF3_GAIN_2      (0x01 << _DAC80508_GAIN_BUFF3_GAIN_POS)
#define DAC80508_GAIN_BUFF3_GAIN_1      (0x00 << _DAC80508_GAIN_BUFF3_GAIN_POS)
#define _DAC80508_GAIN_BUFF2_GAIN_POS   (2)
#define DAC80508_GAIN_BUFF2_GAIN_2      (0x01 << _DAC80508_GAIN_BUFF2_GAIN_POS)
#define DAC80508_GAIN_BUFF2_GAIN_1      (0x00 << _DAC80508_GAIN_BUFF2_GAIN_POS)
#define _DAC80508_GAIN_BUFF1_GAIN_POS   (1)
#define DAC80508_GAIN_BUFF1_GAIN_2      (0x01 << _DAC80508_GAIN_BUFF1_GAIN_POS)
#define DAC80508_GAIN_BUFF1_GAIN_1      (0x00 << _DAC80508_GAIN_BUFF1_GAIN_POS)
#define _DAC80508_GAIN_BUFF0_GAIN_POS   (0)
#define DAC80508_GAIN_BUFF0_GAIN_2      (0x01 << _DAC80508_GAIN_BUFF0_GAIN_POS)
#define DAC80508_GAIN_BUFF0_GAIN_1      (0x00 << _DAC80508_GAIN_BUFF0_GAIN_POS)

#define DAC80508_TRIGGER_ADDR                (0x05)
#define DAC80508_TRIGGER_READ                DAC80508_TRIGGER_ADDR | DAC80508_READ_COMMAND
#define DAC80508_TRIGGER_WRITE               DAC80508_TRIGGER_ADDR | DAC80508_WRITE_COMMAND
#define _DAC80508_TRIGGER_LDAC_POS           (4)
#define DAC80508_TRIGGER_SOFT_LDAC_ON        (0x01 << _DAC80508_TRIGGER_LDAC_POS)
#define DAC80508_TRIGGER_SOFT_LDAC_OFF       (0x00 << _DAC80508_TRIGGER_LDAC_POS)
#define _DAC80508_TRIGGER_SOFT_RESET_POS     (0)
#define DAC80508_TRIGGER_SOFT_RESET_ON       (0x0A << _DAC80508_TRIGGER_SOFT_RESET_POS)
#define DAC80508_TRIGGER_SOFT_RESET_OFF      (0x00 << _DAC80508_TRIGGER_SOFT_RESET_POS)

#define DAC80508_BRDCAST_ADDR                (0x06)
#define DAC80508_BRDCAST_READ                DAC80508_BRDCAST_ADDR | DAC80508_READ_COMMAND
#define DAC80508_BRDCAST_WRITE               DAC80508_BRDCAST_ADDR | DAC80508_WRITE_COMMAND
#define _DAC80508_BRDCAST_POS                (0)

#define DAC80508_STATUS_ADDR                (0x07)
#define DAC80508_STATUS_READ                DAC80508_STATUS_ADDR | DAC80508_READ_COMMAND
#define DAC80508_STATUS_WRITE               DAC80508_STATUS_ADDR | DAC80508_WRITE_COMMAND
#define _DAC80508_STATUS_REF_ALM_POS        (0)

#define DAC80508_DAC_ADDR                (0x08)
#define DAC80508_DAC_READ                DAC80508_DAC_ADDR | DAC80508_READ_COMMAND
#define DAC80508_DAC_WRITE               DAC80508_DAC_ADDR | DAC80508_WRITE_COMMAND
#define _DAC80508_DAC_POS                (0)


#ifdef __cplusplus
}
#endif

#endif /* DAC80508_H_ */
