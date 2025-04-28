/**
*
* @author Zeynep Sude Öncü - zey.su.oncu@gmail.com
* @since 02.04.2024-06.04.2024
* <p>
* mainin ve dosya dolaşıcının bulunduğu sınıftır. Main sınıfı dosya dolaşıcıyı çağırır, dosya dolaşıcı da içinde 
* class bulunan java dosyalarını ayıklayarak diğer sınıfları çağırır ve kodların içinde istenen koşulların adedini ekrana yazdırır.
* </p>
*/

package pkg;

import java.io.IOException;
import java.util.Scanner;
import java.io.File;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.nio.charset.StandardCharsets;
import java.text.DecimalFormat;

public class test {

	public static void main(String[] args) throws IOException, InterruptedException {
		Scanner scn=new Scanner(System.in);
		System.out.println("Taranacak Git reposunun Url'sini giriniz:");
		String gUrl=scn.nextLine();
		gitCloner klon=new gitCloner(gUrl);
		String dosya=klon.cloner(); 
		File gitr= new File(dosya);
		dosyaDolasici(gitr);
		
       	}
	
	public static void dosyaDolasici(File dosya) throws IOException {
        File[] icerik = dosya.listFiles();
        if (icerik != null) {
            for (File gezici : icerik) {
                if (gezici.isDirectory()) { //dosya mı klasör mü kontrolü
                    dosyaDolasici(gezici);
                } 
                else if (gezici.getName().endsWith(".java")) {
                		String kodlar = new String(Files.readAllBytes(Paths.get(gezici.getAbsolutePath())),StandardCharsets.UTF_8);
                		if(kodlar.contains("class")) {
                			javadocSayisi jd=new javadocSayisi(kodlar);
                			yorumSayisi ys=new yorumSayisi(kodlar);
                			kodSatirSayisi kss=new kodSatirSayisi(kodlar);
                			locSayisi ls=new locSayisi(kodlar);
                			fonkSayisi fs=new fonkSayisi(kodlar);
                			yorumSapma yuzde=new yorumSapma();
                			int fonk=fs.sayici();
                			int loc=ls.sayici();  
                			int javadoc=jd.sayici();
                			int kodSatir=kss.sayici();
                			kodSatir-=jd.getJavadoc();
                			int yorum=ys.sayici();
                			float ysYuzde=yuzde.hesaplayici(javadoc, yorum, kodSatir, fonk);
                			DecimalFormat dec = new DecimalFormat("#.##");
                	        String yorSapYuzde = dec.format(ysYuzde);
                			System.out.println("Sınıf:"+gezici.getName());
                			System.out.println("Javadoc Satır Sayısı:"+javadoc);
                			System.out.println("Yorum Satır Sayısı:"+yorum);
                			System.out.println("Kod Satır Sayısı:"+kodSatir);
                			System.out.println("LOC:"+loc);
                			System.out.println("Fonksiyon Sayısı:"+fonk);
                			System.out.println("Yorum Sapma Yüzdesi: %"+yorSapYuzde);
                			System.out.println("------------------------------");
                	    }
                }
            }
        }
    }
}
