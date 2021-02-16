#ifndef HEADER_LCD
#define HEADER_LCD

void config_LCD_user_interface(unsigned char numberOfRows, char UIPointer);
void write_first_line(char *message);
void write_second_line();
void write_at(char line, char row, char character);
void write_line();
int get_string_size(char *string);
void move_UI_pointer_up();
void move_UI_pointer_down();

typedef struct
{
    int numberOfRows;
    char UIPointer;
} InterfaceProperties;

InterfaceProperties g_interfaceProperties = { 0, '~' };

void config_LCD_user_interface(unsigned char numberOfRows, char UIPointer)
{
     if (UIPointer != '^')
     {
         g_interfaceProperties.UIPointer = UIPointer;
     }
    // Since I don't want to write my very own LCD lib right now
    // all I'm gonna do here is call MikroC LCD lib
    Lcd_Cmd(_LCD_CURSOR_OFF);
    write_at(1, 1, g_interfaceProperties.UIPointer);
    g_interfaceProperties.numberOfRows = numberOfRows;
    write_at(2, 16, g_interfaceProperties.numberOfRows + '0');
    return;
}

void write_first_line(char *message)
{
    const char ROW_NUMBER = 1;
    int i;
    for (i = 0; i < get_string_size(message); i++)
    {
        Lcd_Chr(ROW_NUMBER, i + 2, message[i]);
    }
    return;
}

void write_second_line(char *message)
{
    const char ROW_NUMBER = 2;
    int i;
    for (i = 0; i < get_string_size(message); i++)
    {
        Lcd_Chr(ROW_NUMBER, i + 2, message[i]);
    }
    return;
}

void write_at(char line, char row, char character)
{
    Lcd_Chr(line, row, character);
}

int get_string_size(char* string)
{
    int index_and_size = 0;
    while (string[index_and_size] != '\0')
    {
        index_and_size++;
    }
    
    return index_and_size;
}

#endif