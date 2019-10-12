/*
    Copyright 2017 fishpepper <AT> gmail.com

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http:// www.gnu.org/licenses/>.

   author: fishpepper <AT> gmail.com
*/

#include "hal_adc.h"
#include "debug.h"
#include "wdt.h"
#include "config.h"
#include "stm32f0xx_hal.h"

// adc results
volatile uint16_t hal_adc_data[2];

void hal_adc_init(void) {
    hal_adc_init_rcc();
    hal_adc_init_gpio();
    hal_adc_init_mode();
    hal_adc_init_dma();
}

static void hal_adc_init_rcc(void) {
    // // ADC CLOCK = 24 / 4 = 6MHz
    // RCC_ADCCLKConfig(RCC_PCLK2_Div4);

    // // enable ADC clock
    // RCC_APBxPeriphClockCmd(ADC_CLK_RCC, ADC_CLK, ENABLE);

    // // enable dma clock
    // RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);

    // // periph clock enable for port
    // RCC_APBxPeriphClockCmd(ADC_GPIO_CLK_RCC, ADC_GPIO_CLK, ENABLE);
}

static void hal_adc_init_gpio(void) {
    // GPIO_InitTypeDef gpio_init;

    // // set up analog inputs
    // gpio_init.GPIO_Pin  = ADC_IN1_PIN | ADC_IN2_PIN;
    // gpio_init.GPIO_Mode = GPIO_Mode_AIN;
    // GPIO_Init(ADC_GPIO, &gpio_init);
}

static void hal_adc_init_mode(void) {
    // ADC_InitTypeDef adc_init;

    // // ADC configuration
    // adc_init.ADC_Mode = ADC_Mode_Independent;
    // // convert multiple channels
    // adc_init.ADC_ScanConvMode         = ENABLE;
    // // select continuous conversion mode
    // adc_init.ADC_ContinuousConvMode   = ENABLE;
    // // select no external triggering
    // adc_init.ADC_ExternalTrigConv     = ADC_ExternalTrigConv_None;
    // // right 12-bit data alignment in ADC data register
    // adc_init.ADC_DataAlign            = ADC_DataAlign_Right;
    // // 2 channels conversion
    // adc_init.ADC_NbrOfChannel          = 2;

    // // load structure values to control and status registers
    // ADC_Init(ADC, &adc_init);

    // // configure each channel
    // ADC_RegularChannelConfig(ADC, ADC_Channel_1, 1, ADC_SampleTime_41Cycles5);
    // ADC_RegularChannelConfig(ADC, ADC_Channel_2, 2, ADC_SampleTime_41Cycles5);

    // // Enable ADC
    // ADC_Cmd(ADC, ENABLE);

    // // enable DMA for ADC
    // ADC_DMACmd(ADC, ENABLE);

    // // Enable ADC1 reset calibration register
    // ADC_ResetCalibration(ADC);

    // // Check the end of ADC1 reset calibration register
    // while (ADC_GetResetCalibrationStatus(ADC)) {}

    // // Start ADC calibration
    // ADC_StartCalibration(ADC);

    // // Check the end of ADC1 calibration
    // while (ADC_GetCalibrationStatus(ADC)) {}
}

static void hal_adc_init_dma(void) {
//     DMA_InitTypeDef  dma_init;

//     // reset DMA1 channe1 to default values
//     DMA_DeInit(ADC_DMA_CHANNEL);

//     // set up dma to convert 2 adc channels to two mem locations:
//     // channel will be used for memory to memory transfer
//     dma_init.DMA_M2M                 = DMA_M2M_Disable;
//     // setting normal mode (non circular)
//     dma_init.DMA_Mode                = DMA_Mode_Circular;
//     // medium priority
//     dma_init.DMA_Priority            = DMA_Priority_High;
//     // source and destination 16bit
//     dma_init.DMA_PeripheralDataSize  = DMA_PeripheralDataSize_HalfWord;
//     dma_init.DMA_MemoryDataSize      = DMA_MemoryDataSize_HalfWord;
//     // automatic memory destination increment enable.
//     dma_init.DMA_MemoryInc           = DMA_MemoryInc_Enable;
//     // source address increment disable
//     dma_init.DMA_PeripheralInc       = DMA_PeripheralInc_Disable;
//     // Location assigned to peripheral register will be source
//     dma_init.DMA_DIR                 = DMA_DIR_PeripheralSRC;
//     // chunk of data to be transfered
//     dma_init.DMA_BufferSize          = 2;
//     // source and destination start addresses
//     dma_init.DMA_PeripheralBaseAddr  = (uint32_t)&ADC->DR;
//     dma_init.DMA_MemoryBaseAddr      = (uint32_t)hal_adc_data;
//     // send values to DMA registers
//     DMA_Init(ADC_DMA_CHANNEL, &dma_init);

//     // Enable the DMA1 - Channel1
//     DMA_Cmd(ADC_DMA_CHANNEL, ENABLE);

//     // start conversion:
//     hal_adc_dma_arm();

// #if ADC_DO_TEST
//     // TEST ADC
//     while (1) {
//         debug_putc('A');
//         wdt_reset();
//         if (ADC_GetFlagStatus(ADC, ADC_FLAG_EOC) == SET) {
//             uint16_t res = ADC_GetConversionValue(ADC);
//             debug("ADC = "); debug_put_uint16(res); debug_put_newline(); debug_flush();

//             ADC_ClearFlag(ADC, ADC_FLAG_EOC);
//             // start next ADC Software Conversion
//             ADC_SoftwareStartConvCmd(ADC, ENABLE);
//         }
//     }
// #endif  // ADC_DO_TEST
}

static void hal_adc_dma_arm(void) {
    // ADC_SoftwareStartConvCmd(ADC, ENABLE);
}

void hal_adc_process(void) {
    // // adc dma finished?
    // if (DMA_GetITStatus(ADC_DMA_TC_FLAG)) {
    //     // fine, arm DMA again:
    //     hal_adc_dma_arm();
    // } else {
    //     // oops this should not happen
    //     debug_putc('D');
    //     // cancel and re arm dma ???
    // }
}

uint8_t hal_adc_get_scaled(uint8_t ch) {
    // if (ch < 2) {
    //     // 12 bit adc -> scale to 8 bit -> shift by 4
    //     return hal_adc_data[ch]>>4;
    // } else {
    //     debug("hal_adc: channel index out of bounds ");
    //     debug_put_uint8(ch);
    //     debug("allowed 0,1)\n");
    //     debug_flush();
    //     return 0;
    // }
}

