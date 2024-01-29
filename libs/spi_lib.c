
#include "spi_lib.h"


void SPI_CS_Enable(SPI_TypeDef* SPI, unsigned int CS_M)  {
	SPI->CONFIG = (SPI->CONFIG & ~SPI_CONFIG_CS_M) | CS_M;
}


void SPI_CS_Disable(SPI_TypeDef* SPI, unsigned int CS_M)  {
	SPI->CONFIG = (SPI->CONFIG & ~SPI_CONFIG_CS_M) | SPI_CONFIG_CS_NONE_M;
}


void SPI_Init(SPI_TypeDef* s, uint32_t config)
{
	s->ENABLE = 0;
    SPI_ClearRxBuffer(s);
    s->CONFIG = config;
	s->ENABLE = SPI_ENABLE_M;
}


void SPI_WaitTxNotFull(SPI_TypeDef* s)
{
    while ((s->INT_STATUS & SPI_INT_STATUS_TX_FIFO_NOT_FULL_M) == 0) ;
}

int SPI_TimeoutWaitTxNotFull(SPI_TypeDef* s, uint32_t timeout)
{
    while ((s->INT_STATUS & SPI_INT_STATUS_TX_FIFO_NOT_FULL_M) == 0)
    {
        if (timeout-- == 0)
        {
            return -1;
        }
    }
    return 0;
}


void SPI_WaitRxNotEmpty(SPI_TypeDef* s)
{
    while ((s->INT_STATUS & SPI_INT_STATUS_RX_FIFO_NOT_EMPTY_M) == 0) ;
}


int SPI_TimeoutWaitRxNotEmpty(SPI_TypeDef* s, uint32_t timeout)
{
    while ((s->INT_STATUS & SPI_INT_STATUS_RX_FIFO_NOT_EMPTY_M) == 0)
    {
        if (timeout-- == 0)
        {
            return -1;
        }
    }
    return 0;
}


void SPI_ClearRxBuffer(SPI_TypeDef* s)
{
    volatile uint32_t dummy;
    while ((s->INT_STATUS & SPI_INT_STATUS_RX_FIFO_NOT_EMPTY_M) != 0)
    {
        dummy = s->RXDATA;
    }
    (void) dummy;
}


void SPI_Exchange(SPI_TypeDef* s, uint8_t* input_bytes, uint8_t* output_bytes, uint32_t count)
{
    while (count-- > 0)
    {
        SPI_WaitTxNotFull(s);
        s->TXDATA = *input_bytes++;
        SPI_WaitRxNotEmpty(s);
        if (output_bytes != 0)
        {
            *output_bytes++ = s->RXDATA;
        }
        else
        {
            (void)s->RXDATA;
        }
    }

}
















