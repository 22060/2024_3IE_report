public class newClass {

	public static void main(String[] args) {
		// Queue.defaultSize = 10;
		Queue queue = new Queue();
		System.out.println(queue.QueueVolume() + "個目のスタックです");
		Queue tower10 = new Queue(10);
		System.out.println(queue.QueueVolume() + "個目のスタックです");
		tower10 = new Queue();
		// System.out.println(queue.queueCount + "個目のスタックです");
		queue.enqueue(10);queue.printQueue();
		queue.enqueue(20);queue.printQueue();
		// queue.volemu = 0;
		queue.enqueue(30);queue.printQueue();
		queue.enqueue(40);queue.printQueue();
		queue.enqueue(50);queue.printQueue();
		queue.enqueue(60);queue.printQueue();
		// queue.data[0] = 100;
		// queue.printQueue(0);
		System.out.println(queue.dequeue());queue.printQueue(3,4);queue.printQueue();
		System.out.println(queue.dequeue());queue.printQueue();
		System.out.println(queue.dequeue());queue.printQueue();
		System.out.println(queue.dequeue());queue.printQueue();
		System.out.println(queue.dequeue());queue.printQueue();
		System.out.println(queue.dequeue());queue.printQueue();
	}

}
