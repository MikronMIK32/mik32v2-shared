

#include "dma_lib.h"




void DMA_StartNewTask(DMA_CONFIG_TypeDef* dma, uint32_t channel_index, 
                        uint32_t control_value, 
                        uint32_t source_address, uint32_t destination_address, uint32_t length)
{
    
    
    dma->CHANNELS[channel_index].SRC = source_address;
    dma->CHANNELS[channel_index].DST = destination_address;
    dma->CHANNELS[channel_index].LEN = length;
    dma->CHANNELS[channel_index].CFG = control_value | DMA_CH_CFG_ENABLE_M;
}

void DMA_Wait (DMA_CONFIG_TypeDef* dma, uint32_t channel_index)
{

    // uint32_t channel_bits = 0;

    while ((dma->CONFIG_STATUS  & ((1 << channel_index) << DMA_STATUS_READY_S)) == 0) ;
}





/*
void DMA_StartNewLlTask(DMA_CONFIG_TypeDef* dma, uint32_t channel_index,
                        uint32_t task_address)
{
    dma->ENABLE_CH &= ~(1 << channel_index);
    dma->CHANNELS[channel_index].DMA_Cntrl = DMA_CONTROL_linkListEnable_M;
    dma->CHANNELS[channel_index].SRC_DESCRIPTOR = task_address;
    dma->ENABLE_CH |= (1 << channel_index);
}


//�������� ��������� �������� � ���������
unsigned int DMA_Wait_Timeout (DMA_CONFIG_TypeDef* dma, uint32_t channel_index)  {
	unsigned int TIMEOUT = 30000;
	unsigned int wait = 0;
    if ((dma->ENABLE_CH & (1 << channel_index)) == 0)  {
        return 0;
    }

    uint32_t channel_bits = 0;
    channel_bits |= (1 << channel_index) << DMA_DONE_S;
    channel_bits |= (1 << channel_index) << DMA_PERROR_SRC_S;
    channel_bits |= (1 << channel_index) << DMA_PERROR_DST_S;

    //�������� ��������� �������� � ���������
	for(wait=0;wait<TIMEOUT;wait++)  {
    	if((dma->DMA_STATUS & channel_bits) != 0)  {
    		break;
    	}
    }
    if(wait==TIMEOUT)  {
    	return 0;
    }
    return 1;
}



//�������� ���������� ������� � ������
unsigned int DMA_ChnDone (DMA_CONFIG_TypeDef* dma, uint32_t channel_index)  {
    if ((dma->ENABLE_CH & (1 << channel_index)) == 0)  {
        return DMA_CHN_DONE_ERROR_ENABLE;
    }

    uint32_t channel_bits = 0;

    //�������� ����������
    channel_bits = (1 << channel_index) << DMA_DONE_S;
    if((dma->DMA_STATUS & channel_bits) != 0)  {
    	return DMA_CHN_DONE_ERROR_NO;
    }

    //������ ���������
    channel_bits = (1 << channel_index) << DMA_PERROR_SRC_S;
    if((dma->DMA_STATUS & channel_bits) != 0)  {
    	return DMA_CHN_DONE_ERROR_SRC;
    }

    //������ ���������
    channel_bits = (1 << channel_index) << DMA_PERROR_DST_S;
    if((dma->DMA_STATUS & channel_bits) != 0)  {
    	return DMA_CHN_DONE_ERROR_DST;
    }

    return DMA_CHN_DONE_NOT_DONE;
}



//�������� ���������� ������� �� ���� �������
unsigned int DMA_AllChnDone (DMA_CONFIG_TypeDef* dma)  {
    if (dma->ENABLE_CH != DMA_ENABLE_M)  {
        return DMA_CHN_DONE_ERROR_ENABLE;
    }

    //�������� ����������
    if((dma->DMA_STATUS & DMA_DONE_M) == DMA_DONE_M)  {
    	return DMA_CHN_DONE_ERROR_NO;
    }

    //������ ���������
    if((dma->DMA_STATUS & DMA_PERROR_SRC_M) != 0)  {
    	return DMA_CHN_DONE_ERROR_SRC;
    }

    //������ ���������
    if((dma->DMA_STATUS & DMA_PERROR_DST_M) != 0)  {
    	return DMA_CHN_DONE_ERROR_DST;
    }

    return DMA_CHN_DONE_NOT_DONE;
}




*/





