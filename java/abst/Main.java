
public class Main {
        public static void main(String[] args) {
                // みそラーメン
                System.out.println("===みそラーメン===");
                MisoRamen misoRamen = new MisoRamen();
                misoRamen.setRyou(5);
                misoRamen.setKatasa(2);
                misoRamen.setSoup(Taste.しょうゆ);
                misoRamen.setTopping();
                misoRamen.checkRamen();
                misoRamen.setSpice();
                // コーンバター味噌ラーメン
                System.out.println("===コーンバター味噌ラーメン===");
                CornButterMiso cornButterMiso = new CornButterMiso();
                cornButterMiso.setRyou(7);
                cornButterMiso.setKatasa(3);
                cornButterMiso.setSoup(Taste.みそ);
                cornButterMiso.setTopping();
                cornButterMiso.checkRamen();
                // 担々麺
                System.out.println("===担々麺===");
                TantanMen tantanMen = new TantanMen();
                tantanMen.setRyou(8);
                tantanMen.setKatasa(1);
                tantanMen.setSoup(Taste.しょうゆ);
                tantanMen.setTopping();
                tantanMen.checkRamen();
                tantanMen.setLiquid();

        }
}