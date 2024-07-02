// void delete(ListString* s, char x) {  
//     if (s == NULL || s->head == NULL) {  
//         return; 
//     }  
//     Node* cur = s->head; 
//     Node* prev = cur; 
//     while (cur->next != NULL) {  
//         if (cur->next->data == x) { 
//             Node* temp = cur->next;  
//             cur->next = temp->next;  
//             free(temp); 
//         } else {   
//             cur = current->next;  
//         }  
//     }  
// }