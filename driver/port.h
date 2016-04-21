#ifndef SYNCCOM_PORT_H
#define SYNCCOM_PORT_H

#include <ntddk.h>
#include <wdf.h>
#include <defines.h>
#include "trace.h"
#include "fx2Events.h"

EVT_WDF_IO_QUEUE_IO_DEVICE_CONTROL SyncComEvtIoDeviceControl;

NTSTATUS		synccom_port_set_registers(_In_ struct synccom_port *port, const struct synccom_registers *regs);
void			synccom_port_set_register_rep(_In_ struct synccom_port *port, unsigned char offset, unsigned char address, const UINT32 *buf, unsigned write_count);
NTSTATUS		synccom_port_set_register_async(struct synccom_port *port, unsigned char offset, unsigned char address, UINT32 value, EVT_WDF_REQUEST_COMPLETION_ROUTINE write_return);

void			synccom_port_get_registers(_In_ struct synccom_port *port, struct synccom_registers *regs);
synccom_register	synccom_port_get_register_async(struct synccom_port *port, unsigned char offset, unsigned char address, EVT_WDF_REQUEST_COMPLETION_ROUTINE read_return, WDFCONTEXT Context);
synccom_register	synccom_port_get_isr(struct synccom_port *port, EVT_WDF_REQUEST_COMPLETION_ROUTINE read_return, WDFCONTEXT Context);

void			synccom_port_set_clock_bits(_In_ struct synccom_port *port, unsigned char *clock_data);

void			synccom_port_set_memory_cap(struct synccom_port *port, struct synccom_memory_cap *memory_cap);
unsigned		synccom_port_get_input_memory_cap(struct synccom_port *port);
unsigned		synccom_port_get_output_memory_cap(struct synccom_port *port);
unsigned		synccom_port_get_output_memory_usage(struct synccom_port *port);
unsigned		synccom_port_get_input_memory_usage(struct synccom_port *port);

NTSTATUS		synccom_port_purge_tx(struct synccom_port *port);
NTSTATUS		synccom_port_purge_rx(struct synccom_port *port);

void			synccom_port_set_ignore_timeout(struct synccom_port *port, BOOLEAN ignore_timeout);
BOOLEAN			synccom_port_get_ignore_timeout(struct synccom_port *port);

void			synccom_port_set_rx_multiple(struct synccom_port *port, BOOLEAN rx_multiple);
BOOLEAN			synccom_port_get_rx_multiple(struct synccom_port *port);

void			synccom_port_set_wait_on_write(struct synccom_port *port, BOOLEAN wait_on_write);
BOOLEAN			synccom_port_get_wait_on_write(struct synccom_port *port);

NTSTATUS		synccom_port_set_tx_modifiers(struct synccom_port *port, int value);
unsigned		synccom_port_get_tx_modifiers(struct synccom_port *port);

void			synccom_port_set_append_status(struct synccom_port *port, BOOLEAN value);
BOOLEAN			synccom_port_get_append_status(struct synccom_port *port);

void			synccom_port_set_append_timestamp(struct synccom_port *port, BOOLEAN value);
BOOLEAN			synccom_port_get_append_timestamp(struct synccom_port *port);

NTSTATUS		synccom_port_execute_RRES(struct synccom_port *port);
NTSTATUS		synccom_port_execute_TRES(struct synccom_port *port);
unsigned		synccom_port_is_streaming(struct synccom_port *port);
unsigned		synccom_port_has_incoming_data(struct synccom_port *port);
#endif