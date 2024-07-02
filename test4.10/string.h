#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <stdbool.h>  
  
#define MAX_LEN 100 
  
typedef struct {  
    char data[MAX_LEN]; 
    int length;        
} SeqString;  
  
// 初始化顺序串  
void InitString(SeqString *s) {  
    s->length = 0;  
    memset(s->data, 0, MAX_LEN);
}  
  
// 获取顺序串的长度  
int GetLength(SeqString s) {  
    return s.length;  
}  
  
// 获取顺序串指定位置的字符  
char GetChar(SeqString s, int index) {  
    if (index < 0 || index >= s.length) {  
        return '\0'; 
    }  
    return s.data[index];  
}  
  
// 在顺序串末尾添加字符  
bool AddChar(SeqString *s, char c) {  
    if (s->length >= MAX_LEN - 1) {  
        return false;
    }  
    s->data[s->length] = c;  
    s->length++;  
    return true;  
}  
  
// 在顺序串末尾添加字符串  
bool AddString(SeqString *s, SeqString t) {  
    int i;  
    for (i = 0; i < t.length; i++) {  
        if (!AddChar(s, t.data[i])) {  
            return false; 
        }  
    }  
    return true;  
}  
  
// 删除顺序串指定位置的字符  
bool DeleteCharAt(SeqString *s, int index) {  
    if (index < 0 || index >= s->length) {  
        return false;
    }  
    int i;  
    for (i = index; i < s->length - 1; i++) {  
        s->data[i] = s->data[i + 1]; // 将后面的字符前移  
    }  
    s->length--;  
    s->data[s->length] = '\0'; // 确保字符串以null结尾  
    return true;  
}  
  
