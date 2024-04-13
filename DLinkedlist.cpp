# include <iostream>

struct node
{
    node *prev;
    int data;
    node *next;
};

class HeadPointer
{   
    private:

    node *Addr = NULL;
    int listlen = 0;

    public:

    // Defining the 'Insert' method
    void Insert(int data)
    {
        if (Addr != NULL)
        {  
            // Initializing a new node  
            node* Newnode = new node();

            // Inserting data into the new node
            Newnode->data = data;
            
            // Setting the 'previous' pointer of the new node to NULL
            Newnode->prev = NULL;
            
            // Setting the 'next' pointer of the new node to point to the head node
            Newnode->next = Addr;
            
            // Setting the 'previous' pointer of the head node to point to the new node
            Addr->prev = Newnode;
            
            // Setting the Head Pointer to point to the new head node (the new node)
            Addr = Newnode;

            listlen++;
        }
        else
        {   
            // Initializing the Head node 
            Addr = new node();  

            // Setting its pointers to NULL
            Addr->prev = NULL;
            Addr->next = NULL;

            // Insering the data into the node
            Addr->data = data;

            listlen++;
        }    
        
    }

    // Defining the 'PrintList' method
    void PrintList()
    {
        if (Addr != NULL)
        {
            node *itt = Addr;

            std::cout << "\n[";

            while (itt != NULL)
            {
                if (itt->next != NULL)
                {
                    std::cout << itt->data << ", ";
                }
                else
                {
                    std::cout << itt->data;
                }
                

                itt = itt->next;
            } 

            std::cout << "] \n\n";
        }
    }

    // Defining the 'Append' method
    void Append(int data)
    {   // If list lenght > 0 
        if (Addr != NULL)
        {   
            // Initializing an itterator to point to the head node
            node* itt = Addr;

            // Looping and constantly checking if there is a next node
            while(itt->next != NULL)
            {   
                // Moving the itterator to point to the next node
                itt = itt->next;
            }
            
            // Initializing the new node
            node* Newnode = new node();
            
            // Setting the last node's of the list to point to the new node
            itt->next = Newnode;
            
            // Setting the new node 'next' pointer to NULL
            Newnode->next = NULL;

            // Setting the the new node's 'prev' pointer to point to the former last node   
            Newnode->prev = itt;
            
            // Inserting the data into the new node
            Newnode->data = data;

            listlen++;
            
        }
        // If the list is empty
        else
        {   
            // Initializing the Head node 
            Addr = new node();  

            // Setting its pointers to NULL
            Addr->prev = NULL;
            Addr->next = NULL;

            // Insering the data into the new node
            Addr->data = data;
        }    
        

        

    }
    
    // Defining the 'Delete' method
    void Delete(int index)
    {   
        if (index > 0 && index < listlen)
        {   
            // Initializing the iterator to point to the head node
            node* itt = Addr;
            
            // Moving The iterator to point to the given node
            for (int i = 0 ; i < index; i++)
            {
                itt = itt->next;
            }
            
            // Checking if the node is neither the first or last node 
            if (itt->next != NULL && itt->prev != NULL)
            {  
                // Updating the next node 'prev' pointer 
                itt->next->prev = itt->prev;

                // Updating the next node's 'prev' pointer 
                itt->prev->next = itt->next;
            }

            else if(itt->next == NULL && itt->prev != NULL)
            {
                // Updating the next node's 'prev' pointer 
                itt->prev->next = NULL;         
            }
            else if(itt->next == NULL && itt->prev == NULL)
            {   
                // Seting the head pointer to NULL
                Addr = NULL;         
            }
            else
            {
            // Updating the next node 'prev' pointer 
            itt->next->prev = NULL;   

            // Seting the head pointer to NULL
            Addr = itt->next; 
            }

            
            delete(itt);
        }
        else
        {
            std::cout << "\n!! Invalid Index !! ; no nodes have been deleted\n";
            return;
        }
        
    }
};

int main(void)
{

    HeadPointer Headp1;

    // Inserting & Appending new elements to the list (nodes)
    Headp1.Insert(1);
    Headp1.Append(2);
    Headp1.Append(3);
    Headp1.Append(4);
    Headp1.Append(5);

    // Deleting the [2] element from the list
    Headp1.Delete(0);

    // Deleting the [2] element from the list
    Headp1.Delete(1);

    
    // Printing the List's elements
    Headp1.PrintList();
}
