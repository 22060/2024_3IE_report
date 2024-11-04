
public class Queue1 {
	static int QUEUE_LENGTH = 5;
	static int volume = 0;
	static int data[] = new int[QUEUE_LENGTH];

	//データ追加関数 
	static int enqueue(int number) {
		int value;
		//残容量確認 
		if (data.length > volume) {
			//入力値確認 
			if (number > 0) {
				data[volume] = number;
				volume++;
				value = 1;
			} else {
				value = 0;
				System.out.println("wrong input");
			}
		} else {
			System.out.println("queue overflow");
			value = 0;
		}

		return value;
	}

	//データ取得関数 
	static int dequeue() {
		int value;
		//格納個数確認 
		if (volume > 0) {
			value = data[0];
			volume--;

			//空き領域を埋めるためのシフト 
			for (int i = 0; i < QUEUE_LENGTH - 1; i++) {
				data[i] = data[i + 1];
			}
			data[volume] = 0;
		} else {
			value = -1;
		}
		return value;
	}

	//状態表示関数 
	static void printQueue() {
		System.out.print("|");
		for (int i = 0; i < QUEUE_LENGTH; i++) {
			System.out.printf("%d", data[i]);
			System.out.printf("|");
		}
		System.out.println();
	}

	public static void main(String[] args) {
		
		enqueue(10);
		printQueue();
		enqueue(20);
		printQueue();
		enqueue(-20);
		printQueue();
		enqueue(30);
		printQueue();
		enqueue(40);
		printQueue();
		enqueue(50);
		printQueue();
		enqueue(60);
		printQueue();
		System.out.printf("%d\n", dequeue());
		printQueue();
		System.out.printf("%d\n", dequeue());
		printQueue();
		System.out.printf("%d\n", dequeue());
		printQueue();
		System.out.printf("%d\n", dequeue());
		printQueue();
		System.out.printf("%d\n", dequeue());
		printQueue();
		System.out.printf("%d\n", dequeue());
		printQueue();
	}
}
