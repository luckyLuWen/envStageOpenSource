package cn.envStage.web.servlet;

import cn.envStage.domain.NowTime;
import com.fasterxml.jackson.databind.ObjectMapper;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.text.SimpleDateFormat;
import java.util.Date;

@WebServlet("/getInfoServlet")
public class GetInfoServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String para = request.getParameter("para");
        System.out.println(para);

        Date date = new Date();
        SimpleDateFormat ft = new SimpleDateFormat ("yyyy-MM-dd hh:mm:ss");
        System.out.println("当前时间为: " + ft.format(date));

        NowTime nowTime = new NowTime(ft.format(date));

        ObjectMapper mapper = new ObjectMapper();
        response.setContentType("application/json;charset=utf-8");
        mapper.writeValue(response.getOutputStream(),nowTime);
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        this.doPost(request, response);
    }
}
