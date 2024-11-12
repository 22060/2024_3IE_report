public class ChashuMen extends Ramen {
    private int chashu;
    private int men;

    ChashuMen()
    {
            System.out.println("チャーシューメン作るよ");
    }
    ChashuMen(int men, int katasa, Taste taste)
    {
        super(men,katasa,taste);
        System.out.println("指定済みのチャーシューメン作るよ");
        checkChashuMen();
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
    @Override
    public void setSoup(Taste taste) {
        this.soup = Taste.しょうゆ;
        System.out.println("スープ：" + this.soup);
    }
}
