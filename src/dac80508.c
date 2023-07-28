/***********************************************************************************
  * @file    dac80508.c
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

#include "dac80508.h"
#include "dac80508_conf.h"
#include "main.h"

void _DAC80508_write(SPI_HandleTypeDef *hspi, uint8_t *pData){
	// manually operate the !CS signal, because the STM32 hardware NSS signal is (sadly) useless
	HAL_GPIO_WritePin(DAC80508_CHIP_SELECT_GPIO_Port, DAC80508_CHIP_SELECT_GPIO_Pin, GPIO_PIN_RESET);
	HAL_SPI_Transmit(hspi, pData, 3, DAC80508_HAL_TIMEOUT);
	HAL_GPIO_WritePin(DAC80508_CHIP_SELECT_GPIO_Port, DAC80508_CHIP_SELECT_GPIO_Pin, GPIO_PIN_SET);
}

uint16_t _DAC80508_read(SPI_HandleTypeDef *hspi, uint8_t *cmd){
	uint8_t reg8[3];
	HAL_GPIO_WritePin(DAC80508_CHIP_SELECT_GPIO_Port, DAC80508_CHIP_SELECT_GPIO_Pin, GPIO_PIN_RESET);
	HAL_SPI_TransmitReceive(hspi, cmd, reg8, 3, DAC80508_HAL_TIMEOUT);
	HAL_GPIO_WritePin(DAC80508_CHIP_SELECT_GPIO_Port, DAC80508_CHIP_SELECT_GPIO_Pin, GPIO_PIN_SET);
	uint16_t value = (reg8[1]  << 8) | reg8[2];
    return value;
}

/**
 * @brief  Initializes the DAC80508 chip according to user config
 * @note   must be edited by the user
 */
void DAC80508_init(SPI_HandleTypeDef *hspi){
	uint8_t cmd[3] = {0,0,0};

	// 16-bit CONFIG registers
	cmd[0]  = DAC80508_SYNC_WRITE;
	cmd[1] = (uint8_t)((DAC80508_USERCONF_SYNC >> 8) & 0xff);
	cmd[2] = (uint8_t)(DAC80508_USERCONF_SYNC & 0xff);
	_DAC80508_write(hspi, cmd);

	cmd[0]  = DAC80508_CONFIG_WRITE;
	cmd[1] = (uint8_t)((DAC80508_USERCONF_CONFIG >> 8) & 0xff);
	cmd[2] = (uint8_t)(DAC80508_USERCONF_CONFIG & 0xff);
	_DAC80508_write(hspi, cmd);

	cmd[0]  = DAC80508_GAIN_WRITE;
	cmd[1] = (uint8_t)((DAC80508_USERCONF_GAIN >> 8) & 0xff);
	cmd[2] = (uint8_t)(DAC80508_USERCONF_GAIN & 0xff);
	_DAC80508_write(hspi, cmd);

	cmd[0]  = DAC80508_TRIGGER_WRITE;
	cmd[1] = (uint8_t)((DAC80508_USERCONF_TRIGGER >> 8) & 0xff);
	cmd[2] = (uint8_t)(DAC80508_USERCONF_TRIGGER & 0xff);
	_DAC80508_write(hspi, cmd);

}

/**
 * @brief resets the configuration to the default values
 * @todo  test this function
 */
void DAC80508_reset(SPI_HandleTypeDef *hspi){
	uint8_t cmd[3] = { 0, 0, 0 };
	cmd[0] = DAC80508_TRIGGER_WRITE;
	cmd[3] = DAC80508_TRIGGER_SOFT_RESET_ON;
	_DAC80508_write(hspi, cmd);
}

/**
 * @brief Reads DAC80508 chip registers
 * @todo  test these functions
 */

uint16_t DAC80508_read_DEV_ID(SPI_HandleTypeDef *hspi)
{
	uint8_t cmd[3] = { 0, 0, 0 };
	cmd[0] = DAC80508_DEV_ID_READ;
	return _DAC80508_read(hspi, cmd);
}

uint16_t DAC80508_read_SYNC(SPI_HandleTypeDef *hspi)
{
	uint8_t cmd[3] = { 0, 0, 0 };
	cmd[0] = DAC80508_SYNC_READ;
	return _DAC80508_read(hspi, cmd);
}

uint16_t DAC80508_read_CONFIG(SPI_HandleTypeDef *hspi)
{
	uint8_t cmd[3] ={ 0, 0, 0 };
	cmd[0] = DAC80508_CONFIG_READ;
	return  _DAC80508_read(hspi, cmd);
}

uint16_t DAC80508_read_GAIN(SPI_HandleTypeDef *hspi)
{
	uint8_t cmd[3] ={ 0, 0, 0 };
	cmd[0] = DAC80508_GAIN_READ;
	return  _DAC80508_read(hspi, cmd);
}

uint16_t DAC80508_read_TRIGGER(SPI_HandleTypeDef *hspi)
{
	uint8_t cmd[3] ={ 0, 0, 0 };
	cmd[0] = DAC80508_TRIGGER_READ;
	return  _DAC80508_read(hspi, cmd);
}

uint16_t DAC80508_read_DAC(SPI_HandleTypeDef *hspi, uint8_t ch)
{
	uint8_t cmd[3] ={ 0, 0, 0 };
	cmd[0] = (uint8_t)(DAC80508_DAC_READ) + ch;
	return  _DAC80508_read(hspi, cmd);
}

/**
 * @brief Writes to DAC80508 chip registers
 * @todo  test these functions
 */

void DAC80508_write_DAC(SPI_HandleTypeDef *hspi, uint8_t ch, uint16_t val)
{
	uint8_t cmd[3] ={ 0, 0, 0 };
	cmd[0] = (uint8_t)(DAC80508_DAC_WRITE) + ch;
	cmd[1] = (uint8_t)((val >> 8) & 0xff);
	cmd[2] = (uint8_t)(val & 0xff);
	_DAC80508_write(hspi, cmd);
}

