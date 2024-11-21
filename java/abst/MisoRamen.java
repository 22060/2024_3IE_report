
public class MisoRamen extends Ramen implements Spice
{
        MisoRamen()
        {
                System.out.println("みそラーメンを作るよ");
        }

        public void setTopping()
        {
                topping = "ニンニク";
                System.out.println("トッピング：" + topping);
        }

        public void setSoup(Taste taste)
        {
                this.soup = Taste.みそ;
                System.out.println("スープ：" + this.soup);
        }

        public void setSpice()
        {
                System.out.println("スパイス：唐辛子");
        }
}