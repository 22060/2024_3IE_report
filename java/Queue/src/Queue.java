
public class Queue {
	private int volume;
	private int data[];
	private final static int defaultSize = 5;
	private static int queueCount = 0;

	Queue() {
		this(defaultSize);
	}

	Queue(int n) {
		data = new int[n];
		System.out.println(data.length + "個分のキュー生成");
		queueCount++;
		// System.out.println(queueCount + "個目のスタックです");
	}

	int enqueue(int number) {
		int value;
		// 残容量確認
		if (data.length > volume) {
			// 入力値確認
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

	// データ取得関数
	int dequeue() {
		int value;
		// 格納個数確認
		if (volume > 0) {
			value = data[0];
			volume--;

			// 空き領域を埋めるためのシフト
			for (int i = 0; i < data.length - 1; i++) {
				data[i] = data[i + 1];
			}
			data[volume] = 0;
		} else {
			value = -1;
		}
		return value;
	}

	// 状態表示関数
	void printQueue() {
		this.printQueue(0, data.length);
		// System.out.print("|");
		// for (int i = 0; i < data.length; i++) {
		// 	System.out.printf("%d", data[i]);
		// 	System.out.printf("|");
		// }
		// System.out.println();
	}

	private void printQueue(int num){
		System.out.print(data[num]);
	}

	// 状態表示関数
	void printQueue(int start, int end) {
		System.out.print("|");
		for (int i = start; i < end; i++) {
			printQueue(i);
			System.out.printf("|");
		}
		System.out.println();
	}

	int QueueVolume() {
		return queueCount;
	}
}
