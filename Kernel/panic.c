/*
	This file is part of NativeOS.
	Copyright (C) 2015 Dani Rodríguez

	panic.c - kills the kernel in case of a critical error.
*/

#include <kernel/kernel.h>
#include <driver/vga.h>

/* Defined in bootstrap.s */
extern void kdie();

/*
	Prints a kernel panic message into the framebuffer. The message will
	display the provided error code as an argument. If an extra message
	is given, it will be printed to the screen as well.

	After printing the message, the kdie() function will be invoked.
	Therefore, this function will NOT return because of an infinite loop.
*/

void kpanic(int errcode, char* extra)
{
	/* Set up the VGA framebuffer. */
	VGACon_SetColor(COLOR_WHITE, COLOR_RED);
	VGACon_Gotoxy(0, 0);

	/* Print the message. */
	printk("KERNEL PANIC\n");
	printk("Error code: %d", errcode);
	if (extra) {
		printk("\nMessage: %s", extra);
	}

	/* Halt the system. */
	kdie();
}

void bsod(struct idt_data* data)
{
	VGACon_SetColor(COLOR_LIGHT_GRAY, COLOR_BLUE);
	VGACon_Clrscr();
	VGACon_Gotoxy(15, 10);
	printk("An error has ocurred and unfortunately NativeOS is");
	
	VGACon_Gotoxy(15, 11);
	printk("unable to continue normally. Some information might");
	
	VGACon_Gotoxy(15, 12);
	printk("have been lost.");
	
	VGACon_Gotoxy(15, 15);
	printk("Stack Trace:");
	
	VGACon_Gotoxy(15, 16);
	printk("Interrupt Code: 0x%x", data->int_no);
	
	VGACon_Gotoxy(15, 17);
	printk("EAX = %x  EBX = %x  ECX = %x  EDX = %x",
			data->eax, data->ebx, data->ecx, data->edx);
	
	VGACon_Gotoxy(15, 18);
	printk("ESI = %x  EDI = %x  EBP = %x  ESP = %x",
			data->esi, data->edi, data->ebp, data->ebp);
	
	VGACon_SetColor(COLOR_BLUE, COLOR_LIGHT_GRAY);
	VGACon_Gotoxy(35, 7);
	printk(" NativeOS ");
}