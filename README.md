# Internet-of-Things

## 🔧 Dự án: Điều khiển LED ma trận 8x32 qua Bluetooth

### 📌 Mô tả
Dự án này là sản phẩm nghiên cứu và thực hành của nhóm sinh viên nhằm tìm hiểu ứng dụng của **Internet of Things (IoT)** trong điều khiển thiết bị. Cụ thể, nhóm thực hiện việc **hiển thị chữ và thông điệp lên bảng LED ma trận 8x32** bằng cách sử dụng **Arduino** kết hợp với **Bluetooth Serial Monitor**.

---

### 🛠️ Công nghệ & phần cứng sử dụng
- **Arduino UNO**
- **Module Bluetooth HC-05**
- **LED ma trận 8x32** sử dụng **IC MAX7219**
- **Phần mềm Arduino IDE**
- **Điện thoại Android** (ứng dụng gửi dữ liệu qua Bluetooth)

---

### 💡 Chức năng chính
- Ghép nối điện thoại với Arduino qua Bluetooth.
- Gửi văn bản từ điện thoại → hiển thị nội dung lên LED ma trận.
- Tự động cuộn chữ nếu dài hơn chiều rộng ma trận.
- Dễ dàng thay đổi thông điệp hiển thị từ xa.

---

### 🧩 Cách hoạt động
1. Kết nối mạch LED và module Bluetooth với Arduino theo sơ đồ đấu nối.
2. Tải code từ file `Group03_SE1848.ino` lên Arduino.
3. Kết nối điện thoại với module HC-05 (mặc định pass: `1234`).
4. Mở ứng dụng Bluetooth Serial Monitor.
5. Gửi nội dung văn bản → chữ sẽ hiển thị trên bảng LED.

---

### 📂 Cấu trúc thư mục
- `Group03_SE1848.ino` – Code Arduino chính.
- `IEEE Conference Template/` – Tài liệu báo cáo theo định dạng IEEE.
- `README.md` – Tài liệu mô tả dự án.
- `.gitignore` – Các file/thư mục được loại trừ khỏi Git.

---

### 👨‍💻 Thành viên nhóm
- Trương Văn Quyến – Mạch điện & lập trình Arduino
- Nguyễn Đức Đạt – Thiết kế phần cứng
- Trần Bình Đoan Trinh – Tài liệu & trình bày
- Trang Lê Minh Thư – Tích hợp Bluetooth & demo
- Lương Ngọc Thùy Dương – Quản lý nhóm & báo cáo

### 📝 Giấy phép
Dự án được phát triển phục vụ mục đích học tập và nghiên cứu.

---

