package cn.envStage.web.listener;



import javax.servlet.ServletContextEvent;
import javax.servlet.ServletContextListener;
import javax.servlet.annotation.WebListener;
import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketTimeoutException;

@WebListener()
public class ClientListener implements ServletContextListener{

    private MyThread myThread;

    public ClientListener(){
    }

    public void contextInitialized(ServletContextEvent sce) {

        try{
            if (myThread == null){
                int port = Integer.parseInt("8090");
                myThread = new MyThread(port);
            }
            //myThread.start();
        }catch (IOException e){
            e.printStackTrace();
        }

    }

    public void contextDestroyed(ServletContextEvent sce){

        if (myThread != null && myThread.isInterrupted()){
              myThread.interrupt();
        }

    }

}

class MyThread extends Thread{

//    public void run(){
//        while (!this.isInterrupted()){
//            try {
//                Thread.sleep(2000);
//            }catch (InterruptedException e){
//                e.printStackTrace();
//            }
//            System.out.println("执行时间：" + System.currentTimeMillis());
//        }
//    }

    private ServerSocket serverSocket;

    public MyThread(int port) throws IOException
    {
        serverSocket = new ServerSocket(port);
        serverSocket.setSoTimeout(10000);
    }

    public void run()
    {

         while(true){

             try {
                 Socket socket = serverSocket.accept();
                 BufferedReader bufferedReader =new BufferedReader(new InputStreamReader(socket.getInputStream(),"UTF-8"));
                 String str;
                 while ((str = bufferedReader.readLine())!=null){
                     System.out.println(str);
                 }
             }catch(SocketTimeoutException s) {
//                 s.printStackTrace();
             }catch(IOException e) {
//                 e.printStackTrace();
             }
         }



    }
}