public class CornButterMiso extends Ramen {
    public CornButterMiso() {
        System.out.println("コーンバター味噌ラーメン");
    }

    protected void setTopping() {
        topping = "コーンバター";
        System.out.println("トッピング：" + topping);
    }
    @Override
    public void setSoup(Taste taste) {
        this.soup = Taste.みそ;
        System.out.println("スープ：" + this.soup);
    }

}
