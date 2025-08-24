# my-lang


my-lang — bu C tilida yozilgan minimal interpretator bo‘lib, dasturlash tillari qanday ishlashini o‘rganish uchun yaratilgan. Loyiha parser, lexer va interpretator kabi asosiy komponentlarni o‘z ichiga oladi va oddiy skriptlarni bajarish imkonini beradi.

📌 Xususiyatlar

	Minimal va oson tushuniladigan kod tuzilmasi

	C tilida yozilgan parser va interpretator

	Oddiy sintaksis: o‘zgaruvchilar, ifodalar, chiqish buyruqlari

	Ta’lim va eksperimentlar uchun mos

	🛠 Talablar

	my-langni ishga tushirish uchun quyidagilar kerak bo‘ladi:

	Linux/MacOS (yoki Windows’da WSL)

	gcc yoki boshqa C kompilyatori

	make utilitasi

⚙️ O‘rnatish

Repository’ni klon qiling

	git clone https://github.com/root0x7/my-lang.git
	cd my-lang


Loyihani kompilyatsiya qiling

	make


O‘rnatilganligini tekshirish

	./my-lang --version


Agar versiya ko‘rsatilsa, hammasi to‘g‘ri o‘rnatilgan.

🚀 Foydalanish
Oddiy skript yozish

Masalan, example.z faylini oching va quyidagini yozing:

	var x = 10;
	print("Hello, World!");
	print(x);

	Skriptni ishga tushirish
	./my-lang example.z


Natija:

	Hello, World!
	10

📂 Loyiha tuzilmasi
my-lang/
├── src/            # Manba kodi
├── examples/       # Namunaviy skriptlar
├── Makefile        # Tuzish uchun
├── example.z       # Oddiy skript namunasi
└── lang.out        # Chiqarilgan natijalar

🤝 Hissa qo‘shish

Loyihaga hissa qo‘shish uchun:

	Fork qiling

	O‘z branch’ingizda o‘zgarish kiriting

	Pull Request yuboring