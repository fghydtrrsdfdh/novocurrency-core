<template>
  <div class="send-novo">
    <div class="main">
      <input
        v-model="amount"
        ref="amount"
        type="number"
        placeholder="0.00"
        min="0"
      />
      <input
        v-model="address"
        type="text"
        :placeholder="$t('send_novo.enter_novo_address')"
      />
      <input
        v-model="label"
        type="text"
        :placeholder="$t('send_novo.enter_label')"
      />

      <input
        v-model="passwordInput"
        type="password"
        v-show="password === null"
        :placeholder="$t('send_novo.enter_password')"
      />
    </div>
    <button @click="send">{{ $t("buttons.send") }}</button>
  </div>
</template>

<script>
import { mapState } from "vuex";
import UnityBackend from "../../../unity/UnityBackend";
import EventBus from "../../../EventBus";

export default {
  name: "SendNovo",
  data() {
    return {
      amount: null,
      address: null,
      label: null,
      passwordInput: null
    };
  },
  computed: {
    ...mapState(["password"])
  },
  mounted() {
    this.$refs.amount.focus();
  },
  methods: {
    send() {
      /*
       todo:
        - validate input
        - unlock wallet
        - send novo
        - show success / error notification
       */
    }
  }
};
</script>

<style lang="less" scoped>
.send-novo {
  height: 100%;

  display: flex;
  flex-direction: column;

  & .main {
    flex: 1;
  }
}

input {
  border: 0;
  margin: 0 0 10px 0;
  font-style: normal;
  font-weight: 400;
  font-size: 14px;
}

button {
  width: 100%;
}
</style>