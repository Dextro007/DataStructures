Node* sortedMerge(Node* head1, Node* head2)  
{  
   Node* result = nullptr;
   if(head1 == nullptr){
           result =  head2;
   }
   else if(head2 == nullptr){
           result =  head1;
  }else{
      
      if(head1->data < head2->data){
            head1->next =  sortedMerge(head1->next, head2);
              result = head1 ;
      }
      else{
              head2->next = sortedMerge(head1, head2->next);
              result = head2;
      }
  }
  return result;
} 
