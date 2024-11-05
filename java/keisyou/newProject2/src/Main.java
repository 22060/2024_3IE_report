public class Main {
        public static void main(String[] args) {
                // ラーメンくれ
                System.out.println("===ラーメン===");
                Ramen ramen1 = new Ramen();
                ramen1.setRyou(5);
                ramen1.setKatasa(2);
                ramen1.setSoup(Taste.しょうゆ);
                ramen1.checkRamen();
                // 固めん10 盛りのみそラーメンくれ
                System.out.println("===固めん，10 盛り，みそ===");
                Ramen ramen2 = new Ramen();
                ramen2.setKatasa(1);
                ramen2.setRyou(10);
                ramen2.setSoup(Taste.みそ);
                ramen2.checkRamen();
                // しおラーメン
                Ramen ramen3 = new Ramen();
                ramen3.setKatasa(1);
                ramen3.setRyou(8);
                ramen3.setSoup(Taste.しお);
                ramen3.checkRamen();
                // チャーシューメン
                System.out.println("===普通のチャーシューメン===");
                ChashuMen chashuMen = new ChashuMen();
                chashuMen.setRyou(5);
                chashuMen.setKatasa(2);
                chashuMen.setChashu(5);
                chashuMen.setSoup(Taste.みそ);
                chashuMen.checkChashuMen();
                chashuMen.checkRamen();
                // 野菜たっぷりタンメン
                System.out.println("===野菜たっぷりタンメン===");
                Tanmen tanmen = new Tanmen();
                tanmen.setRyou(5);
                tanmen.setKatasa(2);
                tanmen.setYasai(3);
                tanmen.setSoup(Taste.みそ);
                tanmen.checkTanmen();
                tanmen.checkRamen();
                // 野菜少なめのタンメン
                System.out.println("===野菜少なめのタンメン===");
                Tanmen tanmen2 = new Tanmen();
                tanmen2.setRyou(5);
                tanmen2.setKatasa(2);
                tanmen2.setYasai(1);
                tanmen2.setSoup(Taste.しお);
                tanmen2.checkTanmen();
                tanmen2.checkRamen();

        }
}