FROM node:18
WORKDIR /app
COPY package* ./
RUN npm install
COPY . .
RUN npm run build
CMD ["npm", "run", "preview", "--", "--port", "9090", "--host", "0.0.0.0"]