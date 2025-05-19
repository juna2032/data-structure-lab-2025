//#include "Complex.h"
//#include "SportsCar.h"
//#include "SportsCar2.h"
#include "Music.h"

//void main()
//{
	//Complex a, b, c;
	//a.read( "A =");
	//b.read( "B =");
	//c.add(a, b);
	//a.print ("A = ");
	//b.print ("B = ");
	//c.print ("A+B =");

	//Car myCar;
	//Car momsCar(10, "K5", 2);
	//SportsCar mySecondCar

	//myCar.whereAmI();
	//momsCar.whereAmI();
	//myCar.changeGear(3);
	//momsCar.speedUp();
	//momsCar.display();
	//mySecondCar.bTurbo();

//}

int main()
{
	//music streaming을 생성 
	MusicStreamingService my_service("spotify");
	my_service.addMusic("PolaroidLove", "ENHYPEN", "DIMESION", 2022);
	my_service.addMusic("CAKE", "ITZY", "ALBUM", 2023);
	
	//add by user
	//뮤직객체선언 사용자 입력 받기 그리고 입력받은 값을 선언한 뮤직객체 멤버변수에 하나씩 채우기 마지막으로 뮤직 객체 마이서비스 의 뮤직 리스트에 푸시백하기

//search muic by title 
	string music_title;
	cout << "Enter the Music Title: ";
	cin >> music_title;
	Music* result = my_service.searchByTitle(music_title);
	if (result != NULL) {
		cout << "Found:" << result->getTitle() << "by" << result->getArtist() << endl;
	}

	//search music by artist
	string artist_name;
	cout << "Enter the Artist Name: ";
	cin >> artist_name;
	vector<Music*> artist_result = my_service.searchByArtist(artist_name);
	if (!artist_result.empty()) {
		cout << "Found " << artist_result.size() << " song(s) by " << artist_name << ":\n";
		for (Music* music : artist_result) {
			cout << "- " << music->getTitle() << " (" << music->getAlbum() << ", " << music->getYear() << ")" << endl;
		}
	}
	else {
		cout << "No songs found by " << artist_name << "." << endl;
	}
	

}
