package cn.envStage.web.servlet;

import cn.envStage.domain.ResultInfo;
import cn.envStage.domain.User;
import cn.envStage.service.UserService;
import cn.envStage.service.impl.UserServiceImpl;
import com.fasterxml.jackson.databind.ObjectMapper;
import org.apache.commons.beanutils.BeanUtils;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.lang.reflect.InvocationTargetException;
import java.util.Map;

@WebServlet("/loginServlet")
public class LoginServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException {
        //1.获取用户名和密码数据
        Map<String, String[]> map = request.getParameterMap();

        //获取生成的验证码和表单里输入的验证码
        HttpSession session = request.getSession();
        String checkcode = (String) session.getAttribute("CHECKCODE_SERVER");
        session.removeAttribute("CHECKCODE_SERVER");
        System.out.println("生成的验证码：" + checkcode);
        String check = request.getParameter("check");

        ResultInfo info = new ResultInfo();

        if(true){
            //2.封装User对象
            User user = new User();
            try {
                BeanUtils.populate(user,map);
            } catch (IllegalAccessException e) {
                e.printStackTrace();
            } catch (InvocationTargetException e) {
                e.printStackTrace();
            }

            //3.调用Service查询
            UserService service = new UserServiceImpl();
            User u = service.login(user);

            //4.判断用户对象是否为null
            if(u == null){
                //用户名密码或错误
                info.setFlag(false);
                info.setErrorMsg("用户名或密码错误");
            }

            //6.判断登录成功
            if(u != null ){
                request.getSession().setAttribute("user", u);
                if("user".equals(u.getRole())){
                    info.setAccount(true);
                }else{
                    info.setAccount(false);
                }
                //登录成功
                info.setFlag(true);
//                System.out.println("success");
            }
        }else {
            info.setFlag(false);
            info.setErrorMsg("验证码错误");
        }

//        System.out.println(info);
        ObjectMapper mapper = new ObjectMapper();
        response.setContentType("application/json;charset=utf-8");
        mapper.writeValue(response.getOutputStream(),info);

    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        this.doPost(request, response);
    }

}
