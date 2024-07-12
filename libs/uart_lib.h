#ifndef UART_LIB_H_INCLUDED
#define UART_LIB_H_INCLUDED

/**
    Библиотека для работы с контроллером USART.
*/
#include "mik32_hal_pcc.h"
#include "mik32_hal_gpio.h"
#include "inttypes.h"
#include <stdbool.h>

#include "uart.h"
#include "mcu32_memory_map.h"

#define XPRINTF_NO 0
#define XPRINTF_YES 0xFF
#define XPRINTF_UART_0 1
#define XPRINTF_UART_1 2
#define XPRINTF_BOTH 3
#define XPRINTF_ALL 0xFF

static uint8_t active_uarts = 0;
static uint8_t xprintf_uarts = 0;

void HAL_UART_MspInit(UART_TypeDef *uart);

/** Инициализирует контроллер USART

    Функция задает режим работы и делитель скорости обмена.
    `Скорость обмена = частоты тактирования контроллера / divider`
    \warning Делитель должен быть не менее 16

    \param uart указатель для доступа к UART
    \param divider делитель частоты тактирования контроллера
    \param control1 значение регистра управления 1
    \param control2 значение регистра управления 2
    \param control3 значение регистра управления 3

    \return Если инициализация выполнена успешно,
            то возвращается true

*/
bool UART_Init(UART_TypeDef *uart, uint32_t divider, uint32_t control1, uint32_t control2, uint32_t control3, uint8_t xprintf_allow);

/** Определяет, активен ли передатчик модуля

    \param uart указатель для доступа к UART

    \return Если передача завершена, возвращается true
 */
bool UART_IsTransmissionFinished(UART_TypeDef *uart);

/** Ожидает, пока модуль передаст все записанные в буфер байты

    \param uart указатель для доступа к UART
 */
void UART_WaitTransmission(UART_TypeDef *uart);

/** Ожидает, пока модуль примет данные

    \param uart указатель для доступа к UART
 */
void UART_WaitReceiving(UART_TypeDef *uart);

/** Определяет, был ли байт забран передатчиком из передающего буфера

    \param uart указатель для доступа к UART

    \return Если передающий буфер полон, то возвращается true
 */
bool UART_IsTxBufferFreed(UART_TypeDef *uart);

/** Определяет, полон ли принимающий буфер

    \param uart указатель для доступа к UART

    \return Если в принимающем буфере есть данные, то возвращается true
 */
bool UART_IsRxFifoFull(UART_TypeDef *uart);

/** Определяет, пуст ли принимающий буфер

    \param uart указатель для доступа к UART

    \return Если в принимающем буфере нет данных, то возвращается true
 */
bool UART_IsRxFifoEmpty(UART_TypeDef *uart);

/** Записывает байт в передающий буфер USART
    Функция записывает байт в передающий буфер.
    Если перед записью буфер полон,
    то функция ожидает, пока в буфере не появится место.

    \param uart указатель для доступа к UART
    \param byte отправляемые данные
*/
void UART_WriteByte(UART_TypeDef *uart, uint16_t byte);

/** Читает байт из принимающего буфер USART
    Функция читает байт из принимающего буфера.
    Если перед чтением буфер пуст,
    то функция ожидает приема нового байта.

    \param uart указатель для доступа к UART

    \return принятые данные
*/
uint16_t UART_ReadByte(UART_TypeDef *uart);

/** Записывает массив байт в передающий буфер USART

    \param uart указатель для доступа к UART
    \param byte_array
    \param count
 */
void UART_Write(UART_TypeDef *uart, uint16_t *byte_array, uint32_t count);

/** Читает массив байт из принимающего буфер USART

    \param uart указатель для доступа к UART
 */
void UART_Read(UART_TypeDef *uart, uint8_t *byte_array, uint32_t count);

/** Очищает принимающий буфер

    \param uart указатель для доступа к UART
 */
void UART_ClearRxFifo(UART_TypeDef *uart);

/** Выбирает порты UART для вывода функцией "xprintf".
    Если порт неактивен, то никаких изменений не
    производится.

    \param xprintf_uarts_value бит 0 = UART_0, бит 1 = UART_1
*/
void xprintf_uarts_allow(uint8_t xprintf_uarts_value);

#endif // UART_LIB_H_INCLUDED
