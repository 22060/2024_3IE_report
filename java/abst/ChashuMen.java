public class ChashuMen extends Ramen {
    private int chashu;
    private int men;

    ChashuMen() {
    }

    public void setChashu(int chashu) {
        this.chashu = chashu;
        System.out.println("チャーシュー：" + chashu);
    }

    public void checkChashuMen() {
        System.out.print("チャーシュー：" + chashu);
        if (getSoup() != Taste.しょうゆ) {
            System.out.println("\nしょうゆ味でないのはチャーシューメンではない！");
            System.out.println("しょうゆ味に変えます！");
            setSoup(Taste.しょうゆ);
        }
    }
}
