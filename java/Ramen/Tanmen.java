public class Tanmen extends Ramen{
    private int yasai;
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
