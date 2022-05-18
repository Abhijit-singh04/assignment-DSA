#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
        int data;
        bool Left_Thread, Right_Thread;
        TreeNode *Left, *Right;

        TreeNode(int data)
        {
                this->data = data;
                this->Left = nullptr;
                this->Right = nullptr;
                this->Left_Thread = true;
                this->Right_Thread = true;
        }
};

class Threaded_BinaryTree
{
public:
        int status;
        TreeNode *root, *Dummy;
        Threaded_BinaryTree()
        {
                root = nullptr;
                Dummy = new TreeNode(INT_MIN);

                Dummy->Left = Dummy;
                Dummy->Right = Dummy;
                Dummy->Left_Thread = true;
                Dummy->Right_Thread = false;
                status = 0;
        }
        void insert(int data)
        {
                TreeNode *node = new TreeNode(data);

                status = 1;
                if (root == nullptr)
                {
                        root = node;
                        root->Right = Dummy;
                        root->Left = Dummy;

                        Dummy->Left = root;
                        Dummy->Left_Thread = false;
                }
                else
                {
                        TreeNode *Temp = root;
                        while (true)
                        {
                                if (node->data < Temp->data)
                                {
                                        if (Temp->Left_Thread == true)
                                        {
                                                node->Left = Temp->Left;
                                                node->Right = Temp;
                                                Temp->Left = node;
                                                Temp->Left_Thread = false;

                                                break;
                                        }
                                        else
                                                Temp = Temp->Left;
                                }
                                else
                                {
                                        if (Temp->Right_Thread == true)
                                        {
                                                node->Right = Temp->Right;
                                                node->Left = Temp;
                                                Temp->Right_Thread = false;
                                                Temp->Right = node;
                                                break;
                                        }
                                        else
                                                Temp = Temp->Right;
                                }
                        }
                }
        }
        void preOrder()
        {
                TreeNode *Temp = root;
                bool flag = false;
                while (Temp != Dummy)
                {
                        if (flag == false)
                                cout << Temp->data << "  ";
                        if (Temp->Left_Thread == 0 && flag == false)
                                Temp = Temp->Left;
                        else if (Temp->Right_Thread == false)
                        {
                                Temp = Temp->Right;
                                flag = false; 
                        }
                        else
                        {
                                Temp = Temp->Right;
                                flag = true;
                        }
                }
        }
        void InOrder()
        {
                TreeNode *Temp = Dummy;
                do
                {
                        Temp = InOrderSuccessor(Temp);
                        if (Temp != Dummy)
                                cout << Temp->data << "  ";
                } while (Temp != Dummy);
        }
        TreeNode *InOrderSuccessor(TreeNode *Temp)
        {
                TreeNode *p;
                p = Temp->Right;
                if (Temp->Right_Thread == false)
                {
                        while (p->Left_Thread == false)
                                p = p->Left;
                }

                return p;
        }
};

int main(void)
{

        Threaded_BinaryTree tree;

        int choice;
        do
        {
                cout << "--------Menu------------ ------------------------------------- "
                     << "\n";
                cout << "1. Insert a node in Thread Binary Search Tree "
                     << "\n";
                cout << "2. Display InOrder Traversal "
                     << "\n";
                cout << "3. Display PreOrder Traversal"
                     << "\n";
                cout << "4. Exit !!!"
                     << "\n";
                cout << "------------------------------------------------------------------"
                     << "\n"
                     << "\n";
                cout << "Enter your choice : ";
                cin >> choice;
                switch (choice)
                {
                case 1:
                        cout << "Enter the node value : ";
                        int val;
                        cin >> val;
                        tree.insert(val);
                        cout << "Node inserted in Threaded Binary Search Tree Successfully"
                             << "\n";
                        break;
                case 2:
                        if (tree.status == 0)
                                cout << "Empty Tree ";
                        else
                        {
                                cout << "InOrder Traversal of Threaded Binary Tree: ";
                                tree.InOrder();
                        }
                        cout << "\n";
                        break;
                case 3:
                        if (tree.status == 0)
                                cout << "Empty Tree ";
                        else
                        {
                                cout << "PreOrder Traversal of Threaded Binary Search Tree : ";
                                tree.preOrder();
                        }
                        cout << "\n";
                        break;
                case 4:
                        exit(0);
                default:
                        cout << "wrong choice "
                             << "\n";
                        break;
                }
        } while (choice != -1);
        return 0;
}
