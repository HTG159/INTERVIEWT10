
# Communication Protocols 
## Tổng quan 
Để vi điều khiển có thể đọc dữ liệu từ các cảm biến hoặc một số vi điều khiển khác. Và việc giao tiếp giữa vi điều khiển với các thành phần khác được gọi là giao thức giao tiếp.

## Có 2 loại giao tiếp:

## Song Song:

![](https://dientutuonglai.com/uploads/media/vi-dieu-khien/truyen-song-song.jpg?1615859179920)

Mỗi 1 bit truyền sẽ tương ứng với 1 dây kết nối như trong hình. Nhờ vậy mà có thể truyền cùng lúc 8bit data nên sẽ có tốc độ truyền nhanh nhưng bù lại sẽ tốn rất nhiều dây để kết nối nếu như bit truyền đi là 16 bit 32 bit.

## Nối Tiếp:

### SPI 

SPI – Serial Peripheral Interface:

- Chuẩn giao tiếp nối tiếp.
- Đồng bộ.
- Hoạt động ở chế độ song công (Có thể truyền - nhận cùng thời điểm).
- Một Master có thể giao tiếp với nhiều Slave.
- Sử dụng 4 dây giao tiếp:
        
        +SCK (Serial Clock): Thiết bị Master tạo xung tín hiệu SCK và cung cấp cho Slave.

        +MISO (Master Input Slave Output): Tín hiệu tạo bởi thiết bị Slave và nhận bởi thiết bị Master.

        +MOSI (Master Output Slave Input): Tín hiệu tạo bởi thiết bị Master và nhận bởi thiết bị Slave. 
        
        +SS (Đôi khi CS- Slave Select/Chip Select): Chọn thiết bị Slave cụ thể để giao tiếp. Để chọn Slave giao tiếp thiết bị Master chủ động kéo đường SS tương ứng xuống mức 0 (Low). 

-SPI có thể giao tiếp với nhiều SLAVE.

![image](https://github.com/user-attachments/assets/7b5087b7-a50b-4c5a-83e5-dcae43655dd9)

Các Slave phải có 1 chân CS để giao tiếp tới Master, trong khi đó Master có thể có nhiều chân SS để giao tiếp với nhiều Slave thông qua chân SS được kết nối với chân CS của Slave tương ứng.

-Khung truyền SPI:
- Khi bắt đầu Master sẽ kéo chân SS của Slave muốn giao tiếp xuống mức 0.
- Master sẽ điều khiển chân SCK, và việc truyền nhận dữ liệu sẽ dựa trên xung của chân SCK, với mỗi bit được truyền từ chân MOSI sẽ có 1 bit được truyền lại từ chân MISO.

Các chế độ hoạt động:

-SPI có 4 chế độ hoạt động phụ thuộc vào giá trị 0, 1 của CPOL và CPHA:
- CPOL = 0: Khi không truyền dữ liệu, SCK sẽ ở mức LOW.
- CPOL = 1: Khi không truyền dữ liệu, SCK sẽ ở mức HIGH.
- CPHA = 0: Lấy mẫu ở cạnh đầu tiên của xung.
- CPHA = 1: Lấy mẫu ở cạnh xung sau của xung.

CPOL = 0, CPHA = 0: Lấy bit ở cạnh xung lên đầu tiên của SCK.

CPOL = 0, CPHA = 1: Lấy bit ở cạnh xung xuống, cạnh xung sau của SCK.

CPOL = 1, CPHA = 0: Lấy bit ở cạnh xung xuống đầu tiên của xung SCK.

CPOL = 1, CPHA = 1: Lấy bit ở cạnh xung lên, cạnh xung sau của xung SCK.


![image](https://github.com/user-attachments/assets/030d83f2-7ef1-4c26-b372-5ae42129532b)

### I2C 
-I2C – Inter-Integrated Circuit:
- Giao tiếp nối tiếp.
- Đồng bộ.
- Half duplex (bán song công).
- Có 2 dây:
    - SCL: xung clk đồng bộ.
    - SDA: dây dữ liẹu.
    - Cả 2 dây đều cần trở kéo lên nguồn 5V vì I2C sẽ cấu hình 2 chân ở chế độ open drain.

-I2C có thể giao tiếp với nhiều Slave chỉ qua 2 dây mà không cần chân SS giống SPI. Vì thế tốc độ truyền dữ liệu của I2C sẽ chậm hơn SPI vì phải gửi thêm bit địa chỉ của Slave.

-Khung truyền I2C:
- Start condition: Master sẽ kéo chân SDA từ cao xuống thấp trước chân SCL để báo hiệu sắp bắt đầu truyền hoặc nhận dữ liệu.
- Address Frame: gồm 7 hoặc 10 bit địa chỉ với 1 bit R/W sau đó sẽ đợi ACK từ thiết bị nhận được (có thể là Master hoặc Slave), kéo chân SDA xuống mức 0.
- Truyền dữ liệu: Mỗi khi truyền xong nếu nhận thành công đủ bit dữ liệu Slave sẽ gửi tín hiệu ACK, Master sẽ kéo chân SDA xuống để gửi tín hiệu ACK nếu muốn tiếp tục nhận dữ liệu, nếu không Master sẽ không kéo dây SDA xuống để thiết bị truyền biết là bit NACK từ đó sẽ kết thúc quá trình truyền dữ liệu.
- Stop condition: Để dừng quá trình truyền dữ liệu, Master sẽ kéo dây SDA xuống mức LOW trong khi dây SCL vẫn ở mức HIGH.


![image](https://github.com/user-attachments/assets/b766da9a-1887-4973-9a8f-be7afc1e8370)


### UART 

UART – Universal Asynchronous Receiver/Transmitter:
- Giao tiếp nối tiếp.
- Không đồng bộ.
- Song công(Full duplex).
- Có 2 dây:
    - Tx: Truyền dữ liệu.
    - Rx: Nhận dữ liệu.

-Tốc độ truyền của UART được đặt ở một số chuẩn, chẳng hạn như 9600, 19200, 38400, 57600, 115200 baud và các tốc độ khác. Tốc độ truyền này định nghĩa số lượng bit được truyền qua mỗi giây.
-Vì là một giao tiếp không đồng bộ (không có xung CLK để đồng bộ), nên dẫn đến có một sai số khi truyền trong Baudrate.

-Khung truyền UART:
- Cấu hình baudrate: cả 2 thiết bị đều phải được cấu hình chung baudrate.
- Điều kiện bắt đầu (Start Condition): Khi bắt đầu truyền dữ liệu, thiết bị gửi sẽ kéo tín hiệu TX từ mức cao (idle) xuống mức thấp (0). Bit này báo hiệu rằng sắp truyền dữ liệu.
- Truyền các bit dữ liệu: Dữ liệu được truyền đi theo từng bit, thường là 8 bit (có thể là 5, 6, 7 hoặc 9 bit tùy theo cấu hình). Dữ liệu được truyền theo thứ tự LSB (Least Significant Bit) trước.
- Bit chẵn lẻ (Parity Bit) (nếu có): Đây là bit tùy chọn để kiểm tra lỗi trong quá trình truyền. Có thể là odd parity (chẵn lẻ lẻ) hoặc even parity (chẵn lẻ chẵn). Nếu không sử dụng, quá trình truyền sẽ bỏ qua bit này.
- Bit dừng (Stop Bit): Sau khi truyền xong các bit dữ liệu và (nếu có) bit chẵn lẻ, một hoặc hai bit dừng (1 hoặc 2 bit) được gửi để báo hiệu kết thúc một byte dữ liệu. Stop bit đưa mức tín hiệu trở lại mức cao (idle) để cho biết dữ liệu đã hoàn thành.
![image](https://github.com/user-attachments/assets/d1c196fb-9b17-4f9b-b5aa-90f46fba2737)