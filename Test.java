package com.leo.java;

public class Test {
	public static void main(String[] args) {
		SingleLinkList<Integer> integerList = new SingleLinkList<Integer>();
		integerList.addFirst(8);
		integerList.addFirst(3);
		integerList.addFirst(34);
		integerList.addFirst(12);
		integerList.addFirst(78);
		integerList.addFirst(4);
		
		integerList.traverseList();
		
		//System.out.println("result : " + integerList.find(null));
		
		
//		SingleLinkList<String> stringList = new SingleLinkList<String>();
//		stringList.add("A");
//		stringList.add("Fool");
//		stringList.add("B");
//		stringList.add("C");
//		stringList.add("H");
//		
//		stringList.traverseList();
//		
//		//stringList.insertAfter("Fool", "looF");
//		stringList.insertBefore("A", "LOOF");
//		
//		stringList.traverseList();
		
		
		SingleLinkList<Integer> list = new SingleLinkList<Integer>();
		
		list.add(1);
		list.add(2);
		list.add(3);
		list.add(4);
		list.add(5);
		list.add(6);
		list.add(7);
		list.add(8);
		list.add(9);
		list.add(10);
		list.add(11);
		list.add(12);
		list.add(13);
		list.add(14);
		list.add(15);
		
		//list.traverseList();
		
//		Node<Integer> start = list.getCircularList();
		Node<Integer> start = integerList.getStartNode();
		Node<Integer> rabbit = start;
		Node<Integer> turtle = start;
		
		System.out.println("rabbit : " + rabbit.getNode());
		System.out.println("turtel : " + turtle.getNode());
		
		while(rabbit.getNode() != turtle.getNode()){
			turtle = turtle.getNextNode();
			rabbit = rabbit.getNextNode().getNextNode();
			if(turtle.equals(rabbit)){
				System.out.println("TURTLE : " + turtle.getNode() + " Rabbit : * " + rabbit.getNode());
				System.out.println("Circuler");
				break;
			}
			System.out.println("TURTLE : " + turtle.getNode() + " Rabbit : " + rabbit.getNode());
			
		}
		System.out.println("Done");
	}
}
