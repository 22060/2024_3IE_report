
public class Queue2 {
	static boolean enqueue(Structize data,int number) {
		boolean value;
		//残容量確認 
		if (data.data.length > data.volume) {
			//入力値確認 
			if (number > 0) {
				data.data[data.volume] = number;
				data.volume++;
				value = true;
			} else {
				value = false;
				System.out.println("wrong input");
			}
		} else {
			System.out.println("queue overflow");
			value = false;
		}

		return value;
	}

	//データ取得関数 
	static int dequeue(Structize data) {
		int value;
		//格納個数確認 
		if (data.volume > 0) {
			value = data.data[0];
			data.volume--;

			//空き領域を埋めるためのシフト 
			for (int i = 0; i < data.data.length - 1; i++) {
				data.data[i] = data.data[i + 1];
			}
			data.data[data.volume] = 0;
		} else {
			value = -1;
		}
		return value;
	}

	//状態表示関数 
	static void printQueue(Structize data) {
		System.out.print("|");
		for (int i = 0; i < data.data.length; i++) {
			System.out.printf("%d", data.data[i]);
			System.out.printf("|");
		}
		System.out.println();
	}

	public static void main(String[] args) {
		Structize data = new Structize();
		enqueue(data,10);
		printQueue(data);
		enqueue(data,20);
		printQueue(data);
		enqueue(data,-20);
		printQueue(data);
		enqueue(data,30);
		printQueue(data);
		enqueue(data,40);
		printQueue(data);
		enqueue(data,50);
		printQueue(data);
		enqueue(data,60);
		printQueue(data);
		System.out.printf("%d\n", dequeue(data));
		printQueue(data);
		System.out.printf("%d\n", dequeue(data));
		printQueue(data);
		System.out.printf("%d\n", dequeue(data));
		printQueue(data);
		System.out.printf("%d\n", dequeue(data));
		printQueue(data);
		System.out.printf("%d\n", dequeue(data));
		printQueue(data);
		System.out.printf("%d\n", dequeue(data));
		printQueue(data);
	}
}
