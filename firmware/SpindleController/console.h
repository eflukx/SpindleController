/*
 * console.h
 *
 * Created: 12-6-2017 10:06:56
 *  Author: Rogier Lodewijks
 */ 


#ifndef CONSOLE_H_
#define CONSOLE_H_


void console_init(uint8_t reset_reason);
void print_reset_reason(uint8_t reset_reason);

#define SERIAL_BANNER "  _____       _           _ _\n / ____|     (_)         | | |\n| (___  _ __  _ _ __   __| | | ___\n \\___ \\| '_ \\| | '_ \\ / _` | |/ _ \\\n ____) | |_) | | | | | (_| | |  __/\n|_____/| .__/|_|_| |_|\\__,_|_|\\___|_\n / ____| |        | |           | | |\n| |    |_|_  _ __ | |_ _ __ ___ | | | ___ _ __\n| |    / _ \\| '_ \\| __| '__/ _ \\| | |/ _ \\ '__|\n| |___| (_) | | | | |_| | | (_) | | |  __/ |\n \\_____\\___/|_| |_|\\__|_|  \\___/|_|_|\\___|_|\n"
   


#endif /* CONSOLE_H_ */