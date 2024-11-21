public abstract class Car {
    protected int tire;
    protected int gas;
    protected int nenpi;

    // コンストラクタ
    Car() {
        System.out.println("車をつくるよ");
    }

    // コンストラクタのオーバーロード
    Car(int speed, int door, int tire) {
        System.out.println("車をつくるよ");
        setSpeed(speed);
        setDoor(door);
        setTire(tire);
    }

    // タイヤの設定。異常な場合には補正する
    public abstract void setTire(int tire);

    public abstract void setGas();

    public abstract void setNenpi();

    public int getTire() {
        return tire;
    }

    public int getGas() {
        return gas;
    }

    public int getNenpi() {
        return nenpi;
    }

    public void drive() {
        setGas(getGas() - nenpi);
        System.out.println("ブオン♪残燃料：" + getGas());
    }

}
