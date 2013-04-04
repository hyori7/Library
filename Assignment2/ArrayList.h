#ifndef ARRAYLIST
#define ARRAYLIST

#include <iostream>

template <class T>
class ArrayList
{
private:
	struct node 
	{
		int index;
		T *data;
		node *nextNode;
	};
	
	node *startNode;
	int size;
	int maxSize;
	
public:
	/*	Pre:  true
	 *	Post: a new empty ArrayList object is created
	 */
	ArrayList(void) 
	{
		startNode = NULL;
		size = 0;
		maxSize = 0;
	};
	
	/*	Pre:  true
	 *	Post: nodes of this ArrayList object is deallocated from memory
	 */
	~ArrayList(void);
	
	/*	Pre:  true
	 *	Post: size of the list is returned
	 */
	int getSize(void);
	
	/*	Pre:  true
	 *	Post: maximum size of the list is returned
	 */
	int getMaxSize(void);
	
	/*	Pre:  true
	 *	Post: maximum size of the list is set to the given number
	 */
	void setMaxSize(int aMaxSize);
	
	
	/*	Pre:  true
	 *	Post: a new node with the given data is added to the back of the list
	 */
	int add(T *aData);
	
	/*	Pre:  true
	 *	Post: a new node with the given data is added to the specified index of the list
	 */
	int add(T *aData, int aIndex);
	
	
	/*	Pre:  list not empty
	 *	Post: the node at the given index is removed from the list
	 */
	void remove(int aIndex);
	
	/*	Pre:  list not empty
	 *	Post: the data of the node at the given index is returned
	 */
	T* get(int aIndex);
	
};

template <class T> ArrayList<T>::~ArrayList(void)
{
	node *tempNode1, *tempNode2;
	tempNode1 = startNode;
	
	if (tempNode1->nextNode == NULL) 
	{
		delete tempNode1;
	} 
	else 
	{
		while (tempNode1->nextNode != NULL) 
		{
			tempNode2 = tempNode1->nextNode;
			delete tempNode1;
			tempNode1 = tempNode2;
		}
	}
	
}

template <class T> int ArrayList<T>::getSize(void)
{
	return size;
}

template <class T> int ArrayList<T>::getMaxSize(void)
{
	return maxSize;
}

template <class T> void ArrayList<T>::setMaxSize(int aMaxSize)
{
	maxSize = aMaxSize;
}

template <class T> int ArrayList<T>::add(T *aData)
{
	
	if (maxSize==0 || size<maxSize) {
		
		node *tempNode1, *tempNode2;
		int currentIndex = 0;
		
		tempNode1 = new node;
		tempNode1->data = aData;
		tempNode1->nextNode = NULL;
		tempNode1->index = currentIndex;
		
		if (startNode == NULL) 
		{
			startNode = tempNode1;
		} 
		else
		{
			tempNode2 = startNode;
			
			while (tempNode2->nextNode != NULL) 
			{
				currentIndex = tempNode2->nextNode->index;
				tempNode2 = tempNode2->nextNode;
			}
			
			tempNode2->nextNode = tempNode1;
			tempNode1->index = tempNode2->index+1;
		}
		
		size++;
		return tempNode1->index;
	} else {
		return -1;
	}

	
}

template <class T> int ArrayList<T>::add(T *aData, int aIndex)
{
	
	if (maxSize==0 || size < maxSize) {
		
		node *newNode, *currentNode, *previousNode;
		int currentIndex = 0;
		
		newNode = new node;
		newNode->data = aData;
		newNode->nextNode = NULL;
		newNode->index = currentIndex;
		
		if (startNode == NULL) 
		{
			startNode = newNode;
			currentNode = startNode;
		} 
		else
		{
			currentNode = startNode;
			previousNode = NULL;
			
			while (currentNode->nextNode != NULL && currentNode->index != aIndex) 
			{
				previousNode = currentNode;
				
				currentIndex = currentNode->nextNode->index;
				currentNode = currentNode->nextNode;
			}
			
			if (previousNode==NULL) 
			{
				startNode = newNode;
			} 
			else 
			{
				previousNode->nextNode = newNode;
			}

			newNode->nextNode = currentNode;
			newNode->index = currentNode->index;
			
			//Change all the indices of the following nodes.
			node *tempNode = currentNode;
			while (tempNode->nextNode != NULL) 
			{
				tempNode = tempNode->nextNode;
				tempNode->index = tempNode->index+1;
			}
			
		}
		
		size++;
		return newNode->index;
	} else {
		//throw ArrayOversizeException;
		
		return -1;
	}
	
	
}

template <class T> void ArrayList<T>::remove(int aIndex)
{
	node *tempNode;
	tempNode = startNode;
	
	if (size == 1 && aIndex == 0) 
	{
		startNode = NULL;
		
		delete tempNode;
		size--;
	}
	else 
	{
		node *previousNode = NULL;
		while (tempNode->nextNode != NULL && tempNode->index != aIndex) 
		{
			previousNode = tempNode;
			tempNode = tempNode->nextNode;
		}
		
		//Change all the indices of the following nodes.
		node *tempNode2 = tempNode;
		if (previousNode!=NULL) {
			previousNode->nextNode = tempNode->nextNode;
		}
		else
		{
			startNode = tempNode->nextNode;
		}
		while (tempNode2->nextNode != NULL) 
		{
			tempNode2 = tempNode2->nextNode;
			tempNode2->index = tempNode2->index-1;
		}
		
		delete tempNode;
		size--;
	}
}

template <class T> T* ArrayList<T>::get(int aIndex)
{
	node *tempNode;
	tempNode = startNode;
	
	if (aIndex == 0)
	{
		return tempNode->data;
	}
	else if (aIndex > size-1)
	{
		return NULL;
	}
	
	while (tempNode->nextNode != NULL) 
	{
		tempNode = tempNode->nextNode;
		
		if (tempNode->index == aIndex) 
		{
			return tempNode->data;
		}
	}
	return NULL;
}

#endif