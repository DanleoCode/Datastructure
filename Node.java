package com.leo.java;


/**
 * 
 * @author Dhananjay Tiwari
 *
 * @param <T>
 */
public class Node<T> implements Comparable<T>{

	private T node;
	private Node<T> nextNode;
	private Node<T> previousNode;
	
	@Override
	public int compareTo(Object object) {
		
		@SuppressWarnings("unchecked")
		Node<T> node = (Node<T>) object;
		
		if(Integer.class.isInstance(node.getNode())){
			if(this.node == node.getNode())
				return 0;
			else if((Integer)this.node > (Integer)node.getNode())
				return 1;
			else 
				return -1;
		}
		
		// TODO Auto-generated method stub
		return 0;
	}

	
	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + ((node == null) ? 0 : node.hashCode());
		return result;
	}


	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Node other = (Node) obj;
		if (node == null) {
			if (other.node != null)
				return false;
		} else if (!node.equals(other.node))
			return false;
		if(Integer.class.isInstance(other.getNode())){
			return (Integer)getNode() == (Integer) other.getNode() ? true : false;
		} else if(String.class.isInstance(other.getNode()))
			return ((String) getNode()).equalsIgnoreCase((String) other.getNode()); 
		return true;
	}


	public T getNode() {
		return node;
	}

	public void setNode(T node) {
		this.node = node;
	}

	public Node<T> getNextNode() {
		return nextNode;
	}

	public void setNextNode(Node<T> nextNode) {
		this.nextNode = nextNode;
	}

	@Override
	public String toString(){
		return (String) node;
	}

	public Node<T> getPreviousNode() {
		return previousNode;
	}

	public void setPreviousNode(Node<T> previousNode) {
		this.previousNode = previousNode;
	}
	
}
