/**
*
* @author Zeynep Sude Öncü - zey.su.oncu@gmail.com
* @since 04.04.2024-06.04.2024
* <p>
*  Çoklu yorum satırlarını sayan sınıftır. Sayıcı methodu tek satırlı yorum satırlarını
*  ayıklayarak çoklu yorum satırlarını döndürür. getjavadoc da çoklu yorum satırı açan 
*  karakterlerin kapladığı satır sayısıyla birlikte toplam satır sayısını döndürür.
* </p>
*/

package pkg;


public class javadocSayisi {
	private String kodlar="";
	private Boolean ysatiri=false;
	private Boolean sahteYsatiri=false;
	private int javadoc=0;
	private int javadocsayisi=0;
	
	public javadocSayisi(String kod) {
		kodlar=kod;
	}
	
	public int sayici() {
		int teksatirliys=0,kontrol1=0,kontrol2=0;
		String[] satirlar = kodlar.split("\n");
        for (String satir : satirlar) {
        	kontrol1++;
        	if(sahteYsatiri) {
        		teksatirliys++;
        		sahteYsatiri=false;
        	}
        	if(satir.contains("/*")) {
        		ysatiri=true;
        		kontrol2=kontrol1;
        	}
        	if(ysatiri==true) {
        		javadoc++;
        	}
        	if(satir.contains("*/")) {
        		ysatiri=false;
        		javadoc=javadoc-2;
        		javadocsayisi++;
        		if(kontrol1-kontrol2==2) {
        			sahteYsatiri=true;
        		}
        	}
        	
        }
		return javadoc-teksatirliys;
	}
	public int getJavadoc() {
		return javadoc+2*javadocsayisi;
	}
	       
}

