// Copyright (c) 2018 The Novo developers
// Authored by: Willem de Jonge (willem@isnapp.nl)
// Distributed under the Novo software license, see the accompanying
// file COPYING

package com.novo.unity_wallet.ui.monitor

import android.os.Bundle
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import com.novo.jniunifiedbackend.MonitorListener
import com.novo.jniunifiedbackend.ILibraryController
import com.novo.unity_wallet.R
import com.novo.unity_wallet.UnityCore
import com.novo.unity_wallet.util.AppBaseFragment
import kotlinx.android.synthetic.main.processing_fragment.*
import kotlinx.android.synthetic.main.processing_fragment.view.*
import org.jetbrains.anko.support.v4.runOnUiThread

class ProcessingFragment : AppBaseFragment() {

    override fun onCreateView(inflater: LayoutInflater, container: ViewGroup?,
                              savedInstanceState: Bundle?): View? {
        return inflater.inflate(R.layout.processing_fragment, container, false)
    }

    override fun onWalletReady() {
        val stats = ILibraryController.getMonitoringStats()
        with(stats) {
            view?.let { view ->
                view.processing_group_probable.text = probableHeight.toString()
                view.processing_group_height.text = partialHeight.toString()
                view.processing_group_processed.text = processedSPVHeight.toString()
                view.processing_group_offset.text = partialOffset.toString()
                view.processing_group_length.text = (partialHeight - partialOffset).toString()
                view.processing_group_prune.text = prunedHeight.toString()
            }
        }
    }

    override fun onResume() {
        super.onResume()

        UnityCore.instance.addMonitorObserver(monitoringListener, fun(callback: () -> Unit) { runOnUiThread { callback() } })
    }

    override fun onPause() {
        UnityCore.instance.removeMonitorObserver(monitoringListener)

        super.onPause()
    }

    private val monitoringListener = object : MonitorListener() {
        override fun onPruned(height: Int) {
            this@ProcessingFragment.processing_group_prune?.text = height.toString()
        }

        override fun onProcessedSPVBlocks(height: Int) {
            this@ProcessingFragment.processing_group_processed?.text = height.toString()
        }

        override fun onPartialChain(height: Int, probableHeight: Int, offset: Int) {
            this@ProcessingFragment.processing_group_probable?.text = probableHeight.toString()
            this@ProcessingFragment.processing_group_height?.text = height.toString()
            this@ProcessingFragment.processing_group_offset?.text = offset.toString()
            this@ProcessingFragment.processing_group_length?.text = (height - offset).toString()
        }
    }
}
