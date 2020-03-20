# SoalShiftSISOP20_modul2_T07


## SOAL 3

membuat sebuah program yang dapat menjalankan serangkaian tugas secara bersamaan dengan ketentuan sebagai berikut 
- Tidak boleh memakai system().
- Tidak boleh memakai function C mkdir() ataupun rename().
- Gunakan exec dan fork
- Direktori “.” dan “..” tidak termasuk

tugas tugas tersebut ialah :

### a. membuat 2 direktori
program pertama disuruh untuk membuat 2 direktori yang berbeda dengan nama yang telah ditentukan (sedaap dan indomie)

    else if (NC2 == 0 && NC3 > 0){
    while ((wait(&status)) > 0);
    if (NC1 == 0){
	printf("create file indomie");
      char *statement[] = {"mkdir", "-p","/achsanymous/Desktop/indomie", NULL};
      execv("/bin/mkdir", statement);
     }
     else{
      while ((wait(&status)) > 0);
	printf("create file sedaap");
      sleep(5);
      char *statement[] = {"mkdir", "-p","/home/achsanymous/Desktop/sedaap", NULL};
      execv("/bin/mkdir", statement);
      
1. else if (NC2 == 0 && NC3 > 0){ perintah dijalankan setelah anak ke 3 selesai
2. "mkdir" untuk membuat file/direktori
3. "/achsanymous/Desktop/indomie" nama dan alamat direktori
4. execv("/bin/mkdir", statement) untuk menjalankan/ mengeksekusi perintah 
5. sleep(5); diberi jeda untuk eksekusi
Baru setelah itu eksekusi dilanjutkan membuat direktori kedua

### b. membuka zip
kedua program diharuskan untuk membuka file jpg.zip yang telah disediakan yang nantinya menjadi folder jpg

    else if (NC2 > 0 && NC3 == 0){
      char* statement[] = {"unzip", "-oq","/home/achsanymous/Desktop/jpg.zip", NULL};
	  printf("opening package . . .");
      execv("/usr/bin/unzip", statement);
      
1. Menggunakan anak ke 3 untuk melakukan unzip 
2. "unzip", "-oq" untuk melakukan unzip 
3. "/home/achsanymous/Desktop/jpg.zip" alamat dari jpg.zip(file yang ingin dibuka)
4. execv untuk mengeksekusi
5. /usr/bin/unzip lokasi unzip
6. statement = variabel

setelah child ditunjuk program segera mengeksekusi file jpg.zip untuk dibuka yang nantinya akan terbentuk folder jpg

### c. memisahkan isi dari folder jpg ke 2 folder yang berbeda

ketiga program harus memindahkan isi dari folder jpg ke dalam folder sedaap dan indomie berdasarkan petunjuk yang diberikan yaitu memindahkan file kedalam sedaap dan folder kedalam indomie lalu program dibuat membuat file coba1.txt dan dalam 3 detik kembali membuat file coba2.txt di setiap folder yang telah dipindahkan ke folder indomie

	if (NC2 > 0 && NC3 > 0) {
		while ((wait(&status)) > 0);
		DIR *directory;
		struct dirent *direct;
		chdir("/home/achsanymous/Desktop/jpg/");//membuka file jpg
		directory = opendir(".");

		if (directory){
      		while ((direct = readdir(directory)) != NULL){
	    if(strcmp(direct->d_name, ".") == 0 || strcmp(direct->d_name, "..") == 0)
		      continue;
		    if(StatD(direct->d_name)){
		      if(fork() == 0) {
		        char stage[999];
		        sprintf(stage,"/home/achsanymous/Desktop/jpg/%s",direct->d_name);
		        char* statement[] = {"mv", stage,"/home/achsanymous/Desktop/indomie/", NULL};execv("/bin/mv", statement);
          		}
          	else{
            	while ((wait(&status)) > 0);
            	if(fork() == 0){
            	  	if(fork() == 0){
            	    	char stage1[999];
            	    	FILE *clap;
		        	    sprintf(stage1,"/home/achsanymous/Desktop/indomie/%s/coba1.txt",direct->d_name);		        	    
                  clap = fopen(stage1, "w");
		        	    fclose(clap);
		        	  	}
              		else{
		            	while ((wait(&status)) > 0);
		            	sleep(3);
		            	char stage2[999];
		            	FILE *clap;
		            	sprintf(stage2,"/home/achsanymous/Desktop/indomie/%s/coba2.txt",direct->d_name);		            	
                  clap = fopen(stage2, "w");
		            	fclose(clap);
		            	exit(0);
		          		}}
            	else{
				 while ((wait(&status)) > 0);
					printf("loading . . . ");
					printf(" ");
				      exit(0);
				    }}}
        else{
     		while ((wait(&status)) > 0);
          	if(fork() == 0){
            	while ((wait(&status)) > 0);
            	char stage3[999];
            	sprintf(stage3,"/home/achsanymous/Desktop/jpg/%s",direct->d_name);
            	char* statement[] = {"mv", stage3,"/home/achsanymous/Desktop/sedaap/", NULL};//memindahkan file ke sedaap
            	execv("/bin/mv", statement);
		


1. mengecek isi folder jpg
2. jika berisi foto maka akan di pindahkan ke folder sedaap
3. bila berisi folder akan dipindahkan ke folder indomie
4. setelah folder dipindahkan akan dibuat file txt dan dalam interval 3 detik(seperti yang diminta soal) akan dibuat file txt yang kedua 
5. hal ini dilakukan hingga tidak ada item didalam folder jpg


## kendala
soal no 2 belum dapat kami kerjakan karena tingkat kesulitannya problemnya belum bisa kammi temukan solusinya , terutama karena faktor pengetahuan coding yang belum cukup. 
beberapa anak yang sibuk karena mengurus departemen dan kegiatan lainnya sangat sibuk, terutama dengan kondisi yang dimana sumber daya manusia IT yang sedikit sehingga anak-anak yang sibuk ditambah dengan tugas lainnya mayoritas belum bisa menyelesaikan seluruh soal dengan sempurna.




