package com.leo.java;

/**
 * 
 * @author Dhananjay Tiwari
 *
 * @param <T>
 */

public class SingleLinkList<T> {
	private Node<T> head;
	
	public SingleLinkList(){
		
	}
	
	private Node<T> getNewNode(T value){
		Node<T> node = new Node<T>();
		node.setNode(value);
		node.setNextNode(null);
		return node;
	}
	
	public void add(T value){
		if(this.head != null){
			Node<T> tempNode = head;
			while(tempNode.getNextNode() != null){
				tempNode = tempNode.getNextNode();
			}
			tempNode.setNextNode(getNewNode(value));
		} else {
			head = getNewNode(value);
		}
	}
	
	public void addFirst(T value){
		if(this.head != null){
			Node<T> firstNode = getNewNode(value);
			firstNode.setNextNode(head);
			head = firstNode;
		} else {
			head = getNewNode(value);
		}
	}
	
	public Node<T> getStartNode(){
		return head;
	}
	
	public void traverseList(){
		System.out.println("CAlled");
		Node<T> tempNode = head;
		while(tempNode != null){
			System.out.println(tempNode.getNode());
			tempNode = tempNode.getNextNode();
		}
	}

	
	public boolean find(T t){
		if(head != null){
			Node<T> node = head;
			do{
				if(node.getNode() == t)
					return true;
				node = node.getNextNode(); 
			}while(node != null);
		}
		return false;
	}
	
	public void insertAfter(T node, T value){
		if(head != null){
			Node<T> insertingValue = new Node<T>();
			insertingValue.setNode(node);
			Node<T> temp = head;
			Node<T> newNode = getNewNode(value);
			do{
				if(temp.equals(insertingValue)){
					Node<T> next = temp.getNextNode();
					temp.setNextNode(newNode);
					newNode.setNextNode(next);
					return;
				}
				temp = temp.getNextNode();
			}while(temp != null);
		}
	}
	
	public void insertBefore(T node, T value){
		if(head != null){
			Node<T> newNode = getNewNode(value);
			Node<T> insertBefore = getNewNode(node);
			Node<T> temp = head;
			Node<T> lastNode = head;
			do{
				if(temp.equals(insertBefore)){
					newNode.setNextNode(temp);
					if(temp == head)
						head = newNode;
					else
						lastNode.setNextNode(newNode);
				}
				lastNode = temp;
				temp = temp.getNextNode();
			}while(temp != null);
		}
	}
	
	public Node<T> getLastNode(){
		Node<T> temp = head;
		if(head != null){
			while(temp.getNextNode() != null){
				temp = temp.getNextNode();
			}
		}
		return temp;
	}
	
	public Node<T> getCircularList(){
		Node<T> lastNode = getLastNode();
		Node<T> startNode = head;
		lastNode.setNextNode(startNode);
		return startNode;
	}
}
