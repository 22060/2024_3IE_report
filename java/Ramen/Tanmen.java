public class Tanmen extends Ramen{
    private int yasai;
    Tanmen(){
        System.out.println("タンメン作るよ");
    }
    Tanmen(int ryou,int katasa,Taste taste){
        super(ryou, katasa, taste);
        checkTanmen();
        System.out.println("指定済みのタンメン作るよ");
    }
    public void setYasai(int yasai){
        this.yasai = yasai;
        System.out.println("野菜：" + yasai);
    }
    public void checkTanmen(){
        System.out.print("野菜：" + yasai);
        if(getSoup() != Taste.しお){
            System.out.println("しお味でないのはタンメンではない！");
            System.out.println("しお味に変えます！");
            setSoup(Taste.しお);
        }
    }
}
