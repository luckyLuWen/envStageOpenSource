package cn.envStage.web.filter;

import javax.servlet.*;
import javax.servlet.annotation.WebFilter;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;


@WebFilter("/*")
public class LoginFilter implements Filter {
    public void destroy() {

    }

    public void doFilter(ServletRequest req, ServletResponse resp, FilterChain chain) throws ServletException, IOException {
        System.out.println(req);
        HttpServletRequest request = (HttpServletRequest) req;
        HttpServletResponse response = (HttpServletResponse) resp;


        String uri = request.getRequestURI();

        if(uri.contains("/index.html") || uri.contains("/header.html")  || uri.contains("/footer.html")  ||uri.contains("/login.html") || uri.contains("loginServlet") || uri.contains("testServlet") ||uri.contains("css") || uri.contains("js") || uri.contains("fonts") || uri.contains("images") ||uri.contains("checkCode") ){

            chain.doFilter(req, resp);
        }else{
            Object user = request.getSession().getAttribute("user");
            if(user != null){
                chain.doFilter(req, resp);
            }else{
                response.sendRedirect("login.html");
//                System.out.println("defeat");
            }
        }
    }

    public void init(FilterConfig config) throws ServletException {

    }

}
