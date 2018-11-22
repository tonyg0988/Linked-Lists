#include <iostream>
#include <cstdlib>

using namespace std;

struct lol{
    int element;
    struct lol* next;
    };
void Reverse(struct lol **head_ref){
    int length,done=0,tempo,i;
    struct lol *temp1=*head_ref;
    struct lol *temp=*head_ref;
    /// counting the length
    for(length=0;temp!=NULL;temp=temp->next,length++);
    cout<<"log 1: length is "<<length<<endl;

    while(done<length)
{
            cout<<"log 2: Entered in while loop, done is :"<<done<<" and length is :"<<length<<endl;
            for(i=0,temp=*head_ref;i<done;i++,temp=temp->next); /// moving pointer until done(items which are swapped from front
            cout<<"Log 3: element from front is :"<<temp->element<<endl;
            for(int j=0;j<length-1;j++,temp1=temp1->next); /// moving pointer until length(items which are swapped from back
            cout<<"LOg 4: Element form back is :"<<temp1->element<<endl;

            int tempo=temp->element;
            temp->element=temp1->element;
            temp1->element=tempo;
            cout<<"swapped element "<<temp1->element<<" and "<<temp->element<<endl;
            done++;
            length--;
            temp=*head_ref;
            temp1=*head_ref;
}
}
int n_element(struct lol** head_ref, int position){
    int found=0;
    struct lol* temp =*head_ref;

    for(int i=0;i<position-1;i++){
        temp=temp->next;
            if(temp==NULL){
                cout<<"There is no such position in the linked list"<<endl;
                return found;
                }}
    return (found=temp->element);
}

int search_element(struct lol** head_ref, int element){
    int counter=0;
    struct lol* temp=*head_ref;

    while(temp!=NULL && temp->element!=element){
        temp=temp->next;
        counter++;}

    if(temp==NULL){
        return counter=0;}
    else
        return counter;}

void update_element(struct lol** head_ref, int position , int new_element){

            struct lol* temp=*head_ref;

            for(int i=0;i<position-1;i++){
                temp=temp->next;
                }
            temp->element=new_element;
            return;
    }

void delete_position(struct lol** head_ref, int position){
        struct lol* temp=*head_ref,*prev;
        /// if the position is 1 then head will point to second node
        if(position==1){
            *head_ref=temp->next;
            return;
            }

        /// for moving the head/temp to desired position
        for(int i=0;i<position-1;i++){
            prev=temp;
            temp=temp->next;}

        prev->next=temp->next;
        free(temp);
        return;

}
void delete_node(struct lol** head_ref, int element){

    struct lol* temp=*head_ref,*prev;
    /// when head itself contains the value of element to be deleted
    if(temp!=NULL && temp->element==element){
        *head_ref=temp->next;
        free(temp);
        return;
    }
    /// element is to be searched among the list

    while(temp!=NULL && temp->element!=element){
            prev=temp;
            temp=temp->next;
            }
    if(temp==NULL){
        cout<<"Element not present in linked list"<<endl;
        return;
        }
    else
    {
        prev->next=temp->next;
        free(temp);
    }
}

void print(struct lol* n){
        cout<<endl;
    while(n!=NULL){
        cout<<n->element<<"\t\t";
        n=n->next;
        }
        cout<<endl;
}

void push(struct lol **head_ref, int ipelement){
    /// inserting at the front
    struct lol* new_node= (struct lol*)malloc(sizeof(struct lol));
    new_node->element=ipelement;
    new_node->next=(*head_ref);
    (*head_ref)=new_node;}


bool append(struct lol* head_ref, int position){
    /// inserting at the given position

    int element;
    struct lol* temp=head_ref;

    struct lol* new_node= (struct lol*)malloc(sizeof(struct lol));

    for(int i=0;i<position-1;i++){   /// move pointer at given position and enter right next to it..

            temp=temp->next;
                if(temp==NULL){
        cout<<"Element cant be entered as given position is out of context"<<endl;
        return 0;
        }
    }
    cout<<"enter the element to be entered in list:"<<endl;
    cin>>element;

    new_node->next=temp->next;
    new_node->element=element;
    temp->next=new_node;


}
void ending(struct lol **head_ref, int element){
    /// inseting element at the end of the list
    struct lol* new_node=(struct lol*)malloc(sizeof(struct lol));

    struct lol* last= *head_ref;
    new_node->next = NULL;
    new_node->element  = element;
    if (*head_ref == NULL)
    {
       *head_ref = new_node;  /// assigning/creating new head if list is empty.
       return;
    }
    while(last->next!=NULL)
        {
        last=last->next;     /// moving the pointer until last to enter a node
        }

    last->next=new_node;
    return;}

void Asort(struct lol **head_ref)
{

    /// Sorting Asendingly using bubble sort
    int temp1;  /// to store the temp value
    struct lol* temp = *head_ref;
    struct lol* next,*curr=*head_ref;   /// current and next pointers for respective positon elements
        for(;temp->next!=NULL;temp=temp->next)   /// master loop which will be executed (length) times
        {


            for(curr=*head_ref,next=curr->next;curr->next!=NULL;curr=curr->next,next=curr->next)
            {          /// keeping next pointer ahead to swap the bigger element which is concept of bubble sort


                if(curr->element > next->element)
                { /// if previous element is bigger, swap it with next, so biggest element is pushed at back.
                    temp1=next->element;
                    next->element=curr->element;
                    curr->element=temp1;
                }
            }
        }
}

void Dsort(struct lol **head_ref)
{

    /// Sorting Asendingly
    int temp1;  /// to store the temp value
    struct lol* temp = *head_ref;
    struct lol* next,*curr=*head_ref;
        for(;temp->next!=NULL;temp=temp->next)
        {


            for(curr=*head_ref,next=curr->next;curr->next!=NULL;curr=curr->next,next=curr->next)
            {


                if(curr->element < next->element)
                {
                    temp1=next->element;
                    next->element=curr->element;
                    curr->element=temp1;
                }
            }
        }
}
int main()
{
    int element,position,found;
    int ip;
    struct lol* head =NULL;

    while(true)
{
    fflush(stdin);
    cout<<"\nPress any key to continue...\n";
	fflush(stdin);
	getchar();
    cout<<"1. At front "<<endl<<"2. At end"<<endl<<"3.At desired positon"<<endl;
    cout<<"4. Upate an element"<<endl;
    cout<<"5. Delete an element by position"<<endl<<"6. Delete an element by value"<<endl<<"7. Search Element"<<endl<<"8. Sort Desendingly"<<endl;
    cout<<"9. Sort Asendingly"<<endl<<"10. Reverse the linked list"<<endl<<"11. Print Linked list"<<endl<<"12. Print Nth node"<<endl;
    cout<<"13. for Exit"<<endl;
    fflush(stdin);
    cin>>ip;

    switch(ip)
    {
        case 1:

            cout<<"Enter the element to enter"<<endl;
            cin>>element;
            push(&head,element);
            print(head);
            break;
        case 2:

            cout<<"Enter the element to enter"<<endl;
            cin>>element;
            ending(&head,element);
            print(head);
            break;

        case 3:

            cout<<"enter the position after you want to enter the from the following linked list:"<<endl;
            print(head);
            cin>>position;
            if(append(head,position))
            cout<<"element has been updated and new list is "<<endl;

            print(head);
            break;

         case 4:

            print(head);
            cout<<"enter the positon of element to be updated"<<endl;
            cin>>position;
            cout<<"Enter the value of element to be updated"<<endl;
            cin>>element;
            update_element(&head,position,element);
            cout<<"Element has been updated and new list is "<<endl;
            print(head);
            break;

        case 5:
        /// delete the element by positon in linked list
        print(head);
        cout<<"Enter the positon of element to be deleted"<<endl;
        cin>>position;
        delete_position(&head,position);
        cout<<"New linked list after deletion of element at "<<position<<"is"<<endl;
        print(head);
        break;


        case 6:

            print(head);
            cout<<"Enter the element to be deleted in the list"<<endl;
            cin>>element;
            delete_node(&head,element);
            cout<<"Element has deleted and new list is "<<endl;
            print(head);
            break;


        case 7:

            /// search an itme in linked list
            int found;
            cout<<"Enter the element to be searched"<<endl;
            cin>>element;
            found=(search_element(&head,element));
            if(found){
                cout<<"Element found at positon "<<found<<endl;
                }
            else
                cout<<"Element is not present in the list"<<endl;

            break;
        case 8:
            /// sorting asendingly
            Dsort(&head);
            print(head);
            break;
        case 9:
            /// sorting desendingly
            Asort(&head);
            print(head);
            break;
        case 10:

                // shit goes here;
                Reverse(&head);
                print(head);
                break;
        case 11:
                print(head);
                break;

        case 12:
                cout<<"Enter the index to find the element"<<endl;
                cin>>position;
                found=n_element(&head,position);
                if(found){
                    cout<<"Element found at index "<<position<<" is "<<found<<endl;}
                break;

        case 13:
                cout<<"Exting the system\n";
                exit(1);


        }
    }
}
