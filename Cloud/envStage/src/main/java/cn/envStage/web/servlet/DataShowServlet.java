package cn.envStage.web.servlet;

import cn.envStage.domain.Devices_num;
import cn.envStage.service.DevicesNumService;
import cn.envStage.service.impl.DevicesNumServiceImpl;
import com.fasterxml.jackson.databind.ObjectMapper;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet("/dataShowServlet")
public class DataShowServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

//        Devices_num data = new Devices_num();

        Devices_num data =null;

        DevicesNumService devicesNum = new DevicesNumServiceImpl();

        data = devicesNum.getDevicesNum();
//

//        data.setNum(1);
//        data.setSubNum(2);
//        data.setUserID("0002");

        System.out.println(data);
        System.out.println("hello");

        ObjectMapper mapper = new ObjectMapper();
        response.setContentType("application/json;charset=utf-8");
        mapper.writeValue(response.getOutputStream(), data);
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        this.doPost(request, response);
    }
}
