#include<iostream>
#include<fstream>  // file stream, this data type represent the file stream generally.
#include <sstream>  //parsing inputs and converting strings to numbers.
using namespace std;
struct Node        // doubly link list wala ena ekk
{
	string name;
	long long int phone_number;  //can store a large integer value.
	Node *next;  //used to store the address of the next node in a linked list.
	Node *prev;   // prev is a pointer to a node that points to the previous node in a linked list.
};
class ContactBook    //This is the constructor of the class ContactBook
{
  private:
	Node *head;   //This is a pointer of type Node which is used to point the first node of the list.
	string x;
	long long int y;
  public:
	    ContactBook();
	    void createNode();
	    void display();
	    int search();
        void deleteAllContacts();
        int deleteContactBySearch();
        void bubbleSort();
        int editContacts();
        void oflineSave();
        void reopenCB();
        void structure();
};

ContactBook::ContactBook()   //This is the constructor of the class ContactBook which sets the head of the contact book to null.
		{
			head=NULL;
			x="";  //It also initializes string x and integer y to empty values.
			y=0;
		}


void ContactBook::createNode()
	    {
	    	if(head==NULL)    // checks if the head pointer of the linked list is empty or not.
	    	{
    	    	Node *newer= new Node;   //creates a new node and allocates memory to it.
	    	    cout<<"  Name of Contact: ";
		        cin>>x;      // takes the name of the contact from the user.
		        newer->name=x;   //assigns the name to the node

    		    cout<<"  Phone Number: ";
	    	    cin>>y;          //takes the phone number of the contact from the user.
		        newer->phone_number=y;    //assigns the phone number to the node.

		        newer->next=NULL;       //assigns the next pointer of the node to NULL as no node is created yet.
		        newer->prev==NULL;      //assigns the prev pointer of the node to NULL as no node is created yet.
		        head=newer;             //assigns the head pointer of the linked list to the newly created node.

		        cout<<"  Contact Added"<<endl;
		    }
		    else
		    {

		        Node *newer= new Node;    //creates a new node and allocates memory to it.
	    	    cout<<"  Name of Contact: ";
		        cin>>x;               // takes the name of the contact from the user.
		        newer->name=x;

    		    cout<<"  Phone Number: ";
	    	    cin>>y;
		        newer->phone_number=y;   //assigns the phone number to the node.

		        newer->next=NULL;

		    	Node *temp=head;
		    	while(temp->next!=NULL)
		    	{
		    		temp=temp->next;
		    	}
		    	temp->next=newer;
		    	newer->prev=temp;
		    	cout<<"  Contact Added"<<endl;
			}
		}

void ContactBook::display()
{
	    	Node *temp=head; //Initialized a pointer Node type variable temp and assign the head pointer of the linked list to it.

	    	int count=0;    //Initialized a int type variable count and assign value 0 to it.

	    	if(temp==NULL)   //Checked if the temp pointer points to null then the list is empty.
	    	{
		    	cout<<"  No Contacts... Please Add Some Contacts"<<endl;////Printed a message if the list is empty.
		    	cout<<"  Thanks"<<endl;
	    	}
	    	else
	    	{
	    		bubbleSort();                   //Called the BubbleSort() function to sort the list.
	    		cout<<"  Name: "<<"      Number: \n"<<endl;
	        	while(temp!=NULL)         //Initialized a while loop which will run until the temp pointer points to null.
	        	{
	        	    count++;                       //Increment the count by 1.
		        	cout<<"  "<<temp->name;        //Printed the name part of the contact.
		        	cout<<"          "<<temp->phone_number<<endl;
    		    	temp=temp->next;
	        	}
	        	cout<<"  Total contacts: "<<count<<endl;
	    	}
}

int ContactBook::search()
    	{
    		bool check=false;                  //creating a boolean variable check and assigning it to false
	    	Node *temp=head;                 //creating a pointer to node and making it point to the head of the linked list
	    	cout<<"***********"<<endl;
	    	cout<<"  Press 1 if you want to Search By Name."<<endl;
	    	cout<<"  Press 2 if you want to Search By Number."<<endl;
	    	int command;
	    	cout<<"  Enter the Command: ";
	    	cin>>command;                     	//taking the input and storing it in command

	    	if(command==1 && temp!=NULL)      //checking if the command is 1 and temp is not null
	    	{
	    		cout<<"  Enter the Name to Search: ";
	    		cin>>x;                       //taking the input and storing it in x
		    	while(temp!=NULL)
		    	{
		        	if(temp->name==x)    //checking if the x is equal to the name of the current node
		        	{
		        		cout<<"***********"<<endl;
		        		cout<<"  Name: "<<temp->name<<endl;
		        		cout<<"  Phone Number:"<<temp->phone_number<<endl;
		        		cout<<"***********"<<endl;
		        		check=true;
		        		break;
		        	}
		        	temp=temp->next;
	        	}
	        	if(check==false)
	        	{
	        		cout<<"  Name Not Found"<<endl;
				}
	    	}
	    	else if(command==2)
	    	{
	    		cout<<"  Enter the Number to Search: ";
	    		cin>>y;

	    		while(temp!=NULL)
	    		{
	    	    	if(temp->phone_number==y)
		        	{
		        		cout<<"***********"<<endl;
		        		cout<<"  Name: "<<temp->name<<endl;
		        		cout<<"  Phone Number: "<<temp->phone_number<<endl;
		        		cout<<"***********"<<endl;
		        		check=true;
		        		break;
		        	}
			        temp=temp->next;
	        	}
				if(check==false)
				{
					cout<<"  Number Not Found"<<endl;
				}
	    	}
	    }

 void ContactBook::deleteAllContacts()         //Nadeesha
	    {
	    	Node *temp=head;
	    	Node *temp2;
	    	if(head==NULL)
	    	{
	    		cout<<"  Already Contact Book is Empty"<<endl;
	    		cout<<"***********"<<endl;
			}
			else
			{
				while(temp!=NULL)
				{
					temp2=temp;
					temp=temp->next;
					delete temp2;
				}
				head=NULL;
				cout<<"  Successfully Deleted All Contacts"<<endl;
	    		cout<<"***********"<<endl;
			}
		}

 int ContactBook::deleteContactBySearch()    // Nadeesha
    	{

	    	Node *temp=head;         // This is a pointer create to traverse through the list.
	    	cout<<"***********"<<endl;
	    	cout<<"  Press 1 if you want to Search By name"<<endl;
	    	cout<<"  Press 2 if you want to Search By Number"<<endl;
	    	int command;
	    	cout<<"  Enter the Command: ";
	    	cin>>command;             // This line is take the user input command.

	    	if(command==1)
	    	{
	    		bool Dcheck=false;    // This is a variable 'Dcheck' to store the condition of contact is present or not.
	    		cout<<"  Enter the Name to Delete: ";
	    		cin>>x;               // This line is take the user input name.
	    		while(temp!=NULL)         // This loop is run until the temp pointer reach to the end of the list.
	    		{
	    	    	if(temp->name==x)     // This condition is check if the entered name is present in the list.
		        	{
		        		cout<<"***********"<<endl;
		        		cout<<"  Name: "<<temp->name<<endl;
		        		cout<<"  Phone Number: "<<temp->phone_number<<endl;
		        		cout<<"***********"<<endl;
		        		Dcheck=true;
		        		break;
		        	}
			        temp=temp->next;
	        	}
	        	if(Dcheck==true)
	        	{
	            	int command;
	            	cout<<"  Press 1 to Delete the Contact: ";
	            	cin>>command;
	            	if(command==1 & temp==head)
	            	{
	            		Node *temp1;     // This is a pointer create to delete the node.
	            		temp1=temp;        // This line is store the address of the temp pointer in the temp1 pointer.
	            		temp=temp->next;    // This line is increase the temp pointer to the next node.
	            		delete temp1;

	            		temp->prev=NULL;     // This line is set the previous pointer of the next node to NULL.
	            		head=temp;            // This line is set the head pointer to the next node.
	            		cout<<"  Contact Deleted Success Fully"<<endl;
			    	}
			    	else if(command==1 & temp->next==NULL)   // This condition is check if the user input command is 1 and contact is the last node in the list.
			    	{
			    		temp->prev->next=NULL;     // This line is set the next pointer of the previous node to NULL.
			    		delete temp;
			    		cout<<"  Contact Deleted Success Fully"<<endl;
			    	}
			    	else if(command==1)
			    	{
			    		Node *temp1;
			    		temp1=temp;
			    		temp->prev->next=temp1->next;  ; // This line is set the next pointer of the previous node to next node.
			    		temp->next->prev=temp1->prev;
			    		delete temp1;
			    		cout<<"  Contact Deleted Success Fully"<<endl;
			    	}
			    	else
			    	{
			    		cout<<"  You Enter Wrong Command ... Try Again"<<endl;
		    		}
	            }
	            else if(Dcheck==false)
				{
					cout<<"  Contact of This Name Not Found."<<endl;
			    }
	    	}
	    	else if(command==2)
	    	{
	    		bool Dcheck=false;
	    		cout<<"  Enter the Number to Delete: ";
	    		cin>>y;
	    		while(temp!=NULL)
	    		{
	    	    	if(temp->phone_number==y)
		        	{
		        		cout<<"***********"<<endl;
		        		cout<<"name: "<<temp->name<<endl;
		        		cout<<"Phone Number: "<<temp->phone_number<<endl;
		        		cout<<"***********"<<endl;
		        		Dcheck=true;
		        		break;
		        	}
			        temp=temp->next;
	        	}
	        	if(Dcheck==true)
	        	{
	            	int command;
	            	cout<<"  Press 1 to Delete the Contact: ";
	        	    cin>>command;
    	        	if(command==1 & temp==head)
	            	{
	            		Node *temp1;
	            		temp1=temp;
	        	    	temp=temp->next;
	        		    delete temp1;

    	        		temp->prev=NULL;
	            		head=temp;
	            		cout<<"  Contact Deleted Success Fully"<<endl;
			    	}
				    else if(command==1 & temp->next==NULL)
    				{
	    				temp->prev->next=NULL;
		    			delete temp;
			    		cout<<"  Contact Deleted Success Fully"<<endl;
				    }
				    else if(command==1)
    				{
	    				Node *temp1;
		    			temp1=temp;
			    		temp->prev->next=temp1->next;
				    	temp->next->prev=temp1->prev;
					    delete temp1;
		    			cout<<"  Contact Deleted Success Fully"<<endl;
			    	}
				    else
				    {
				    	cout<<"  You Enter Wrong Command ... Try Again"<<endl;
				    }
	            }
	            else if(Dcheck==false)
				{
					cout<<"  Contact of This Name Not Found."<<endl;
				}
	    	}
	    	else
	    	{
	    		cout<<"  You Enter wrong Command"<<endl;
			}
	    }

void ContactBook::bubbleSort()
        {
        	Node *temp=head; //This line is declaring a node pointer called temp and assign the head node to it.
            Node *i,*j;   //This line is declaring two node pointers i and j.
            string n;
            long long int n2;
            if(temp=NULL)  //This line is checking if the temp node is empty.
            {
            	cout<<"  Empty contact Book"<<endl;
			}
			else
			{
                for(i=head;i->next!=NULL;i=i->next) //This line is a for loop which iterates through the linked list and assign i to the head node and then moves to the next node until it reaches the end of the list.
                {
                    for(j=i->next;j!=NULL;j=j->next) //This line is another for loop which is used to compare two nodes of the linked list.
                    {
                        if(i->name>j->name)  //This line is checking if the name of the first node is greater than the second node.
		                {
                            n=i->name; //This line is assigning the name of the first node to the string variable n.
                            i->name=j->name; //This line is assigning the name of the second node to the first node.
                            j->name=n;   //This line is assigning the name of the first node to the second node.

                            n2=i->phone_number;   //This line is assigning the phone number of the first node to the long long int variable n2.
                            i->phone_number=j->phone_number;   //This line is assigning the phone number of the second node to the first node.
                            j->phone_number=n2;  //This line is assigning the phone number of the first node to the second node.
                        }
                    }
                }
            }
        }

 int ContactBook::editContacts()
    	{
	    	Node *temp=head;  // This will create a temporary node which points to the head of the list
	    	cout<<"***********"<<endl;
	    	cout<<"  Press 1 if you want to Search By Name"<<endl;
	    	cout<<"  Press 2 if you want to Search By Number"<<endl;
	    	int Ecommand;
	    	cout<<"  Enter the Command: ";
	    	cin>>Ecommand;      // This will take the command from the user

	    	if(Ecommand==1)
	    	{
	    		bool Echeck=false;   // This will create a boolean variable Echeck and initialize it with false.
	    		cout<<"  Enter the Name to Edit: ";
	    		cin>>x;          // This will take the name to edit from the user.
	    		while(temp!=NULL)   // This will loop through the list until it reaches the end of the list.
	    		{
	    	    	if(temp->name==x)     // This will check if the name entered by the user is found in the list
		        	{
		        		cout<<"***********"<<endl;
		        		cout<<"Name: "<<temp->name<<endl;
		        		cout<<"Phone Number: "<<temp->phone_number<<endl;
		        		cout<<"***********"<<endl;
		        		Echeck=true;      // This will set the value of Echeck to true
		        		break;
		        	}
			        temp=temp->next;   // This will point the temporary node to the next node
	        	}
	        	if(Echeck==true)
	        	{
	            	int command;
	        	    cout<<"  Press 1 to Edit the Contact: ";
	            	cin>>command;             // This will take the command from the user
	        	    if(command==1)
	        	    {
	        		    cout<<"  Enter New Name: ";
    	        		cin>>x;
	            		cout<<"  Enter New Number: ";
	            		cin>>y;

	            		temp->name=x;        // This will set the name of the contact to the new name
	        	    	temp->phone_number=y;

	        		    cout<<"  Contact Edited Success Fully"<<endl;
			    	}
			    	else
			    	{
					    cout<<"  You Enter Wrong Command ... Try Again"<<endl;
	    	        }
	    	    }
	    	    else if(Echeck==false)
	    	    {
	    	    	cout<<"  Contact Not Found"<<endl;
				}
	        }
	    	else if(Ecommand==2)
	    	{
	    		bool Echeck=false;          // This will create a boolean variable Echeck and initialize it with false.
	    		cout<<"  Enter the Number to Edit: ";
	    		cin>>y;
	    		while(temp!=NULL)           // This will loop through the list until it reaches the end of the list.
	    		{
	    	    	if(temp->phone_number==y)   // This will check if the number entered by the user is found in the list.
		        	{
		        		cout<<"***********"<<endl;
		        		cout<<"Name: "<<temp->name<<endl;
		        		cout<<"Phone Number: "<<temp->phone_number<<endl;
		        		cout<<"***********"<<endl;
		        		Echeck=true;
		        		break;
		        	}
			        temp=temp->next;
	        	}
	        	if(Echeck==true)
	        	{
	            	int command;
	        	    cout<<"  Press 1 to Edit the Contact: ";
	            	cin>>command;
	        	    if(command==1)
	        	    {
	        		    cout<<"  Enter New Name: ";
    	        		cin>>x;
	            		cout<<"  Enter New Number: ";
	            		cin>>y;

	            		temp->name=x;
	        	    	temp->phone_number=y;

	        		    cout<<"  Contact Edited Success Fully"<<endl;
			    	}
			    	else
			    	{
					    cout<<"  You Enter Wrong Command"<<endl;
	    	        }
	        	}
	        	else if(Echeck==false)
	        	{
	        	    cout<<"  There is No Contact of this Number."<<endl;
	            }
	        }
	        else
			{
			    cout<<"  You Enter Wrong Command ... Try Again"<<endl;
			}
	    }

void ContactBook::oflineSave() //This is the declaration of the function OflineSave() which will save the contact book data in a text file.

    	{
    		Node *temp=head;  //Here we declare a Node type pointer 'temp' and assign the value of head Node to it.
    		ofstream myfile ("contactbook.txt");  //create a text file named contactbook.txt.
            if (myfile.is_open())                 //check if the text file is open or not.
            {
            	while(temp!=NULL)         // while loop which will run till the value of temp Node pointer is not equal to NULL.

	        	{
	        	    myfile<<temp->name<<endl;    // This statement will write the name of contact in the text file.
		        	myfile<<temp->phone_number<<endl;
    		    	temp=temp->next;  //This statement will update the value of temp Node pointer to point the next Node of the linked list.

	        	}
                myfile.close();   //This statement will close the text file.
                structure();
            }
            else
            {
            	cout<<"  Thanks file is empty."<<endl;
			}
		}


void ContactBook::reopenCB()   //reopenCB() is a function which is used to reopen the stored contact book. It is used to read the
		                   // file name contactbook.txt and if it is not empty, it stores the name and phone number of contact
		                   // in the linked list. It is done by taking a string and converting it into an integer and then
		                   //storing it in the linked list.
		{
			bool isEmpty;
			ifstream myfile ("contactbook.txt");
            if (myfile.is_open() & myfile.peek() != EOF)
            {
                int i=0;
                while(getline(myfile,x))
                {
                    if(i % 2 == 0)
					{
						if(head==NULL)
	                    {
    	                  Node *newer= new Node;
                          newer->name=x;

	                      newer->next=NULL;
	                      newer->prev==NULL;
	                      head=newer;
		                }
						else
						{
							Node *newer= new Node;

							newer->name=x;
							newer->next=NULL;

							Node *temp=head;
		                	while(temp->next!=NULL)
		                	{
		                		temp=temp->next;
		                	}
		                	temp->next=newer;
		                	newer->prev=temp;
						}
                    }
                   else
                    {
                    	Node *temp=head;
                    	if(temp->phone_number==0)
                    	{

                    		 stringstream convert(x);
			       	         convert>>y;
                             temp->phone_number=y;
						}
						else
						{
							Node *temp=head;
		                	while(temp->next!=NULL)
		                	{
		                		temp=temp->next;
		                	}

		                	stringstream convert(x);
			       	        convert>>y;
		                	temp->phone_number=y;

						}

				    }
                    i++;
                }
            	myfile.close();
            }
            else
            {
            	cout<<"  File is Empty so Cannot open...Sorry"<<endl;
			}
		}

void ContactBook::structure()  // Yasindu
    	{
            cout<<"     *************"<<endl;
	    	cout<<"  1. Add Contact"<<endl;
	    	cout<<"  2. Update the Contact"<<endl;
	    	cout<<"  3. Delete Contact"<<endl;
	    	cout<<"  4. Search Contact"<<endl;
	    	cout<<"  5. Display All Contacts"<<endl;
	    	cout<<"  6. Delete All Contacts"<<endl;
            cout<<"     *************"<<endl;

	    	int Scommand;
	    	cout<<"  Enter the Command: ";
	    	cin>>Scommand; //is used to store the user input in the Scommand variable.
	    	try
	    	{
	    		if(Scommand>=1&&Scommand<=6)  // is used to check if the user entered a valid command.
	    		{
	    			if(Scommand==1) //is used to check if the user entered command 1 which is to add a contact.
	            	{
	            		createNode();  //is used to call the CreateNode() function to add a contact.
	            		oflineSave();  //is used to call the OflineSave() function to save the contact to the file.
	    	        	structure();   //is used to call the Structure() function to show the menu again.
	            	}
	            	else if(Scommand==2)
		        	{
		        		editContacts();
		        		oflineSave();
		        		structure();
			        }
	            	else if(Scommand==3)
	            	{
	    	        	deleteContactBySearch();
	    	        	structure();
	            	}
	            	else if(Scommand==4)
	            	{
	            		search();
	            		structure();
	            	}
	            	else if(Scommand==5)
	            	{
	            		display();
	            		oflineSave();
	            		structure();
	            	}
	            	else if(Scommand==6)
	            	{
	            		deleteAllContacts();
	            		oflineSave();
	            		structure();
		        	}
				}
				else
				{
					throw(Scommand);
				}
			}
			catch(int Scommand)
			{
				cout<<"  You Enter wrong Command... Run the Code Again"<<endl;
				structure();
			}
	    }


int main()
{
    ContactBook cb;
    cb.reopenCB();
	string n;
	cout<<"  What is Your Name: ";
	cin>>n;

        cout<<"          *************"<<endl;
	cout<<"  "<<n<<"  WELCOME TO CONTACTBOOK      "<<endl;
         cout<<"         *************"<<endl;
	cb.structure();
	return 0;
}


